/*
 * PingObservable.cpp
 *
 * Observer class that controls pushes WatchState and DeviceState
 * updates to objects that implement the abstract Observer class.
 * These are all Node objects and ErrorMessager Object(s).
 *
 *  Created on: Jan-April 2015
 *  Author: James Child
 */

#ifndef PINGOBSERVABLE_H_
#define PINGOBSERVABLE_H_
#include <functional> // for std::function
#include <vector>
#include <map>
#include <utility>     // for std::forward
#include <string>

#include <future>		/* async thread */
#include <thread>
#include <pthread.h>

/* Related Classes */
#include "ErrorMessager.h"
#include "Observer.h"
#include "Ping.h"
#include "FileManager.h"
using namespace std;

class PingObservable{
private:
	mutex mtx;             // mutex for critical section
	vector <Observer*>observers; //Collection of observers
	Observer *err_ob;// polymorphic creation using composition
	Ping *ping = new Ping("","");
	FileManager *fm = new FileManager();

	string ip_addr;
	string filename;
	int monitoring_state;
	int start_toggle;

	void notify_no_response(string ip_address, string name);
	void notify_of_response(string ip_address);
	void notify_all();
	void thread_observe();

public:
	PingObservable();
	void attach(Observer *obs);
	void detach(string ip_address);
	void notify_echo_result(int result, string addr, string name);
	void set_monitoring_state(int mon);
	void read_echo_result(string addr);
	void start_monitoring_state();
        int isMonitoring();
	string toString();
};
#endif /* PINGOBSERVABLE_H_ */
