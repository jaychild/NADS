/*
 * SaveState.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#include "SaveState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one SaveState
 */
SaveState* SaveState::save_singleton = NULL;

/*
 * returns the instance of the class
 */
SaveState* SaveState::getInstance(){
   if (!save_singleton) // Only allow one instance of class to be generated.
      save_singleton = new SaveState();
   return save_singleton;
}

string SaveState::get_id(){
	return id;
}
string SaveState::get_name(){
	return name;

}
void SaveState::run_options(){
	system("clear");
	cout<<"________Save Configuration________" << endl;
	cout<<"> Are you sure you want to save? yes/no" << endl;
	cout << ">";
	string choice = "";
	cin >> choice;
	if(choice == "yes"){
		con->save_state();
		cout << "> Configuration saved!" << endl;
	}else{
		cout << "> Save aborted." << endl;
	}
	cout << "\n> Press return to continue" << endl;
	cin.ignore();
	cin.ignore();
}



