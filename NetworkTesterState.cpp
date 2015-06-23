/*
 * NetworkTesterState.cpp
 *@Author: James Child
 * Jan-April 2015
 */

#include "NetworkTesterState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one NetworkTesterState
 */
NetworkTesterState* NetworkTesterState::tester_singleton = NULL;

/*
 * returns the instance of the class
 */
NetworkTesterState* NetworkTesterState::getInstance(){
   if (!tester_singleton) // Only allow one instance of class to be generated.
      tester_singleton = new NetworkTesterState();
   return tester_singleton;
}

string NetworkTesterState::get_id(){
	return id;
}
string NetworkTesterState::get_name(){
	return name;

}
void NetworkTesterState::run_options(){
	system("clear");
	cout << "_______________Network Tester_______________" << endl;
	cout << "> Warning! This could take a few minutes..." << endl;
	cout << "> Please specify IPv4 or Web Address" << endl;
	cout << ">";
	string addr;
	cin >> addr;

	cout << "> Please specify a port Number" << endl;
	cout << ">";
	string port;
	cin >> port;

	int check_connection = con->configure_test_host(addr, port); //port number is being changed to 4??
	if(check_connection == 1){
		cout << "> Network access available" << endl;
	}else if(check_connection == 0){
		cout << "> Network access unavailable" << endl;
	}else if(check_connection == 2){
		cout << "> Socket creation error" << endl;
	}else if(check_connection == 3){
		cout << "> Cannot establish connection with server" << endl;
	}
	else if(check_connection ==-2){
		cout << "> No network access" << endl;
	}

	cout << "> Press return to continue" << endl;
	cin.ignore();
	cin.ignore();
}


