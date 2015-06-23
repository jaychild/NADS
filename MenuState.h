/*
 * MenuState.h
 * Created: Jan-April 2015
 *@Author: James Child
 */

#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#include <string>
#include <map>
#include "StateInterface.h"
using namespace std;

class MenuState{
private:
	string id = "0";
	string name = "Menu";
	string get_id();
	string get_name();
	StateInterface* get_state(int id);

public:
	MenuState();
	void run_options();
	/*
	 * Converts a string to an Integer
	 * @returns int
	 */
	int stringToInt(string s);
	/*
	 * Reads input from the terminal
	 * @returns int option
	 */
	int get_option();
	/*
	 * Runs the terminal IO, executing a function
	 * based on the users interaction via terminal.
	 */
	void run_menu();
};
#endif /* MENUSTATE_H_ */
