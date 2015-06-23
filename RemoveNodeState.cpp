/*
 * RemoveNodeState.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#include "RemoveNodeState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one RemoveNodeState
 */
RemoveNodeState* RemoveNodeState::remove_singleton = NULL;

/*
 * returns the instance of the class
 */
RemoveNodeState* RemoveNodeState::getInstance(){
   if (!remove_singleton) // Only allow one instance of class to be generated.
      remove_singleton = new RemoveNodeState();
   return remove_singleton;
}


string RemoveNodeState::get_id(){
	return id;
}
string RemoveNodeState::get_name(){
	return name;

}
void RemoveNodeState::run_options(){
	system("clear");
	int error = 0;
	cout << "____________Remove Network Device____________"<<endl;
	cout << "> Please specify the IP Address for removal" << endl;
	cout<<">";
	string ip_address = read_to_string();

	error = con->removeNode(ip_address);
	if(error==1){
		cout << "> Device with ip " + ip_address + " successfully removed.\n" << endl;
	}else if(error ==0){
		cout << "> " + ip_address << " does not exist.\n" << endl;
	}
	cout<< "> Press return to continue" << endl;
	cin.ignore();
}


