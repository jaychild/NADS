/*
 * StatState.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#include "StatState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one StatState
 */
StatState* StatState::stat_singleton = NULL;

/*
 * returns the instance of the class
 */
StatState* StatState::getInstance(){
   if (!stat_singleton) // Only allow one instance of class to be generated.
      stat_singleton = new StatState();
   return stat_singleton;
}

string StatState::get_id(){
	return id;
}
string StatState::get_name(){
	return name;

}
void StatState::run_options(){
	system("clear");
	cout << "______**Network Device Statistics**______" << endl;
	string out = con->getStatistics();
	cout << out << endl;
	cout << "Press return to continue" << endl;
	cin.ignore();
}
