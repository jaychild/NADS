/*
 * AddNodeState.cpp
 *
 *  Created on: Jan - April 2015
 *      Author: James Child 
 */
#include "AddNodeState.h"
#include "MenuState.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h> 
using namespace std;

/*
 * global static point that insures only one AddNodeState
 */
AddNodeState* AddNodeState::add_singleton = NULL;

/*
 * returns the instance of the class
 */
AddNodeState* AddNodeState::getInstance(){
   if (!add_singleton) // Only allow one instance of class to be generated.
      add_singleton = new AddNodeState();
   return add_singleton;
}

string AddNodeState::get_id(){
	return id;
}

string AddNodeState::get_name(){
	return name;
}

/*
 * Runs the terminal IO, executing a function
 * based on the users interaction via terminal.
 */
void AddNodeState::run_options(){
	system("clear");
	cout << "__________Add Network Device__________"<<endl;

	int error = 0;
	cout <<"> Please enter the device name"<<endl;
	cout<<">";
	string device_name = read_to_string();

	cout <<"> Please specify the IP Address"<<endl;
	cout<<">";
	string ip_address = read_to_string();

	int check = con->check_ip_format(ip_address);

	if(check ==1){

		cout <<"> Please state the type of network device"<<endl;
		cout<<">";
		string device_type = read_to_string();
		con->addNode(device_name,ip_address,device_type);

		if(error==1){
			cout <<"> Error: Device already exists!"<<endl;
		}
	}else{
		cout <<"> Error: IP incorrect format"<<endl;
	}

	cout<< "\n> Press return to continue" << endl;
	cin.ignore();
}
