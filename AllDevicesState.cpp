/*
 * AllDevicesState.cpp
 *
 *  Created on: 23 Mar 2015
 *      Author: James Child
 */
#include "AllDevicesState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one RemoveNodeState
 */
AllDevicesState* AllDevicesState::view_singleton = NULL;



/*
 * returns the instance of the class
 */
AllDevicesState* AllDevicesState::getInstance(){
   if (!view_singleton){ // Only allow one instance of class to be generated.
      view_singleton = new AllDevicesState();
   }
   return view_singleton;
}

//AllDevicesState::AllDevicesState(){
//
//}


string AllDevicesState::get_id(){
	return id;
}
string AllDevicesState::get_name(){
	return name;

}
void AllDevicesState::run_options(){
	system("clear");
	string string_out = con->listNodes();
	cout << "____________________________**Currently Configured Devices**____________________________ " << endl;
	cout << string_out;
	cout << "\n> Press return to continue " << endl;
	cin.ignore();
}



