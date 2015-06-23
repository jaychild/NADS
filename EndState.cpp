/*
 * EndState.cpp
 * Created on: Jan-April 2015
 * @Author: James Child
 */
#include "EndState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one EndState
 */
EndState* EndState::end_singleton = NULL;

/*
 * returns the instance of the class
 */
EndState* EndState::getInstance(){
   if (!end_singleton) // Only allow one instance of class to be generated.
      end_singleton = new EndState();
   return end_singleton;
}

string EndState::get_id(){
	return id;
}

string EndState::get_name(){
	return name;
}

void EndState::run_options(){
	system("clear");
	cout << "____________Stop Monitoring____________\n"<<endl;
        int monitoring = con->isMonitoring();
        switch(monitoring){
            case 0:
                cout<<"> Monitoring process already inactive" <<endl;
                cout << "> Press return to continue" << endl;
                cin.ignore();
                break;
            
            case 1:
                con->cancelWatch();
                cout << "> Monitoring process stopped!"<<endl;
                cout << "> Press return to continue" << endl;
                cin.ignore();
                break;                
        }       
}/*Runs the EndState*/



