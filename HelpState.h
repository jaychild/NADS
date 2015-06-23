/*
 * HeloState.h
 * Created: Jan-April 2015
 *@Author: James Child
 */

#ifndef HELPSTATE_H_
#define HELPSTATE_H_
#include "StateInterface.h"
using namespace std;
class HelpState: public StateInterface{
private:
	string id = "9";
	string name = "Help";
	static HelpState* help_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	static HelpState* getInstance();
};


#endif /* HELPSTATE_H_ */
