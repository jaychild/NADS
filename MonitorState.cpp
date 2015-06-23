/*
 * MonitorState.cpp
 * Created: Jan-April 2015
 *@Author: James Child
 */
#include "MonitorState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one MonitorState
 */
MonitorState* MonitorState::watch_singleton = NULL;

/*
 * returns the instance of the class
 */
MonitorState* MonitorState::getInstance(){
   if (!watch_singleton) // Only allow one instance of class to be generated.
      watch_singleton = new MonitorState();
   return watch_singleton;
}

string MonitorState::get_id(){
	return id;
}
string MonitorState::get_name(){
	return name;

}
void MonitorState::run_options(){
	system("clear");
	cout << "____________Monitor Devices____________\n"<<endl;
        int monitoring = con->isMonitoring();
        switch(monitoring){
            case 1:
                cout<<"> You're already monitoring devices";
                cin.ignore(); 
                break;
                
            case 0:
                cout << "> Determining connection, please wait..." << endl;                
                unsigned int a = con->check_connection();       
                if(a==1){
                        con->thread_watch();
                        cout << "> Monitoring Process Started" << endl;
                }else{
                        cout << "> Internet Connection Unavailable" << endl;
                }
                cout << "> Press return to continue" << endl;
                cin.ignore(); 
                break;
        }       	
}



