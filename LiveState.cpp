/*
 *LiveState.cpp
 * Created: Jan-April 2015
 *@Author: James Child
 */
#include "LiveState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one RemoveNodeState
 */
LiveState* LiveState::live_singleton = NULL;

/*
 * returns the instance of the class
 */
LiveState* LiveState::getInstance(){
   if (!live_singleton){ // Only allow one instance of class to be generated.
      live_singleton = new LiveState();
   }
   return live_singleton;
}

string LiveState::get_id(){
	return id;
}

string LiveState::get_name(){
	return name;
}

void LiveState::run_options(){    
    cout << "Not yet implemented - a future development!" << endl;
    cout << "Press return to continue" << endl;
    cin.ignore();
}
