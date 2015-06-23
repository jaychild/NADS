/*
 * MenuState.cpp
 * Created: Jan-April 2015
 *@Author: James Child
 * Creates the Menu
 */

#include "MenuState.h"
#include "StateInterface.h"
#include "AddNodeState.h"
#include "RemoveNodeState.h"
#include "AllDevicesState.h"
#include "StatState.h"
#include "MonitorState.h"
#include "EndState.h"
#include "NetworkTesterState.h"
#include "SaveState.h"
#include "HelpState.h"
#include "LiveState.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

/*
 * global static point that insures only one NetworkTester
 */
vector<StateInterface*>options;
MenuState::MenuState(){
	StateInterface *s1 = AddNodeState::getInstance();
	StateInterface *s2 = RemoveNodeState::getInstance();
	StateInterface *s3 = AllDevicesState::getInstance();
	StateInterface *s4 = StatState::getInstance();
	StateInterface *s5 = MonitorState::getInstance();
	StateInterface *s6 = EndState::getInstance();
	StateInterface *s7 = NetworkTesterState::getInstance();
	StateInterface *s8 = SaveState::getInstance();
	StateInterface *s9 = HelpState::getInstance();
        StateInterface *s10 = LiveState::getInstance();
	options.push_back(s1);
	options.push_back(s2);
	options.push_back(s3);
	options.push_back(s4);
	options.push_back(s5);
	options.push_back(s6);
	options.push_back(s7);
	options.push_back(s8);
	options.push_back(s9);
        options.push_back(s10);
}

string MenuState::get_id(){
	return id;
}

string MenuState::get_name(){
	return name;
}

StateInterface* MenuState::get_state(int id){
	string s_id= static_cast<ostringstream*>( &(ostringstream() << id) )->str();
	StateInterface *temp;
	for(unsigned int i = 0; i<options.size();i++){
		if(options[i]->get_id()==s_id){
			temp = options[i];
		}
	}
	return temp;
}

/*
 * Converts a string to an Integer
 * @returns int
 */
int MenuState::stringToInt(string s){
	int value = atoi(s.c_str());
	return value;
}

/*
 * Reads input from the terminal
 * @returns int option
 * This generates the menu list dynamically and assigns input values!
 */
int MenuState::get_option(){
	system("clear");
	int option;
	string mystr;
	string opt;
	cout << " _____________Tasks_____________" << endl;
	for(unsigned int i = 0; i<options.size();i++){
		StateInterface *sinter = options[i];
		opt = sinter->get_id() + ": " + sinter->get_name() + "\n";
		cout << " " << opt;
	}
	cout << " Enter " << options.size()+1 << " to quit" << endl;
	cout << " _______________________________" << endl;
	cout << "" << endl;
	cout<<">";

	getline(cin,mystr);
	option = stringToInt(mystr);
	return option;
}

/*
 * Runs the terminal IO, executing a function
 * based on the users interaction via terminal.
 */
void MenuState::run_options(){
	int choice = 0; //= getOption();
	int size = options.size()+1;
	while(choice!=size){
		choice = get_option();
		if(choice > 0 && choice < size){
			get_state(choice)->run_options();
		}
	}
}/*dynamically assigns a kill key*/




