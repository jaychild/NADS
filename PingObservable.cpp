/*
 * PingObservable.cpp
 *
 * Observer class that controls pushes WatchState and DeviceState
 * updates to objects that implement the abstract Observer class.
 * These are all Node objects and ErrorMessager Object(s).
 *
 *  Created on: Jan-April 2015
 *      Author: James Child
 */
#include <functional> // for std::function
#include <vector>
#include <map>
#include <utility>     // for std::forward
#include <string>
#include <iostream>
#include <fstream>
#include <thread>

#include "PingObservable.h"
#include "ErrorMessager.h"
#include "Observer.h"
#include "Node.h"
#include "AllNodes.h"
#include "Ping.h"
#include "NetworkTester.h"
using namespace std;
AllNodes *an;
NetworkTester *nt;

/*
 * constructor
 * initializes ErrorMessager observer
 */
PingObservable::PingObservable(){
	filename = "";
	an = AllNodes::getInstance();
	nt = NetworkTester::getInstance();
	err_ob = new ErrorMessager(); //polymorphic composition
        start_toggle = 0;
        monitoring_state=0;
	std::thread second_thread(&PingObservable::thread_observe,this);
	second_thread.detach();
}

/*
 * Controls the state of the PingObservable state (adapted Observer Pattern)
 * If the class state changes between 0 and 1, the Observable class "pushes"
 * the update to all Observer classes by calling either the update() or
 * update_monitoring() functions, inherited from the abstract class Observer.
 */
void PingObservable::thread_observe(){
    int count = 0;
	while(1){
		usleep(1000);
		if((monitoring_state==0) && (start_toggle!=0)){
			mtx.lock();
			for(unsigned int i = 0; i<observers.size();i++){
				Observer *obvs = observers[i];
				obvs->update();
			}
			mtx.unlock();
			err_ob->update();
		}else if((monitoring_state==1) && (start_toggle!=0)){
			mtx.lock();
			for(unsigned int i = 0; i<observers.size();i++){
				Observer *obvs = observers[i];
				obvs->update_monitoring();
			}
			mtx.unlock();
			err_ob->update_monitoring();
		}
                if(count==15000){
                    err_ob->clear_buffer();
                    //cout << "How Frequent" << endl;
                    count = 0;
                }
                count++;
	}
}

/*
 * registers observers in a map, using ip_address as a key
 */
void PingObservable::attach(Observer *obs){
	mtx.lock();
	observers.push_back(obs);
	mtx.unlock();
}

/*
 * removes a registered Observer with specific IP
 */
void PingObservable::detach(string ip_address){
	for(unsigned int i = 0; i<observers.size(); i++){
		Observer *a = observers[i];
		mtx.lock();
		string temp_ip = a->virtual_ip_address();
		mtx.unlock();
		if(temp_ip==ip_address){
			mtx.lock();
			observers.erase(observers.begin()+i);
			mtx.unlock();
		}
	}
}

/*
 * spawns an error message for a no response
 */
void PingObservable::notify_no_response(string ip_address, string name){
	for(unsigned int i = 0; i<observers.size(); i++){
		mtx.lock();
		string ip  = observers[i]->virtual_ip_address();
		mtx.unlock();
		//cout << ip << " this is not responding" << endl;
		if(ip_address==ip){
			mtx.lock();
			observers[i]->virtual_no_response("","");
			mtx.unlock();
		}
	}
	err_ob->virtual_no_response(ip_address,name);
}

/*
 * notifies selected observers of DeviceState change
 */
void PingObservable::notify_of_response(string ip_address){
	for(unsigned int i = 0; i<observers.size(); i++){
		mtx.lock();
		string ip  = observers[i]->virtual_ip_address();
		mtx.unlock();
		//cout << ip << " this is responding" << endl;
		if(ip_address==ip){
			mtx.lock();
			observers[i]->virtual_is_responding();
			mtx.unlock();
		}
	}
}

/*
 * notifies all Node observers of WatchState change
 */
void PingObservable::notify_all(){
	for(unsigned int i = 0; i<observers.size(); i++){
		observers[i]->virtual_being_watched();
	}
}

void PingObservable::notify_echo_result(int result, string addr, string name){
	if(result==0){
		notify_no_response(addr,name);
		//cout << "Found the file and there's no responds" << endl;
	}else if(result == 1){
		notify_of_response(addr);
		//cout << "Found the file and there is respond" << endl;
	}
}

/*
	 * sets the monitoring state. 0 for not monitoring,
	 * 1 for monitoring
	 */
	void PingObservable::set_monitoring_state(int mon){
		monitoring_state = mon;
	}

/*
 * Monitor Devices - this is going to be the
 * observable state, observed by the observers.
 */
void PingObservable::start_monitoring_state(){
	unsigned int result,size = 0;
	start_toggle++;
	monitoring_state=1;
	string addr = "";
        string name = "";

	while(monitoring_state==1){
		size = an->get_collection_size();
		for(unsigned int i=0; i<size;i++){
			int net_error =nt->check_network_connection();
			//cout << "Check network" << net_error;
			if(net_error==1){
				mtx.lock();
				Node obvs = an->get_node_object(i);
				mtx.unlock();
				addr = obvs.getip_address();
                                name = obvs.getName(); 
				ping->build_command(addr);
				ping->ping_node();
				result = fm->read_echo_result(addr);
				fm->remove_file(addr);
				notify_echo_result(result, addr, name);
			}else{
				monitoring_state=0;
			}
		}
	}
	//monitoring_state=0;
}

string PingObservable::toString(){
	string str;
	for(unsigned int i = 0; i<observers.size(); i++){
		mtx.lock();
		str+=observers[i]->toString() + "\n";
		mtx.unlock();
	}
	return str;
}

/*
 * Returns 1 if monitoring 0 if not
 */
int PingObservable::isMonitoring(){
    return monitoring_state;
}




