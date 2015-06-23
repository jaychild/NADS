/*
 * AddNodeState.h
 *
 *Created on: Jan-April 2015
 *@Author: James Child
 */

#ifndef ADDNODESTATE_H_
#define ADDNODESTATE_H_
#include "StateInterface.h"

using namespace std;

class AddNodeState: public StateInterface{

private:
	string id = "1";
	string name = "Add Node";
	static AddNodeState* add_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	static AddNodeState* getInstance();

};

#endif /* ADDNODESTATE_H_ */
