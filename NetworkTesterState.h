/*
 * NetworkTesterState.h
 *@Author: James Child
 * Jan-April 2015
 */

#ifndef NETWORKTESTERSTATE_H_
#define NETWORKTESTERSTATE_H_
#include "StateInterface.h"
using namespace std;
class NetworkTesterState: public StateInterface{
private:
	string id = "7";
	string name = "Configure Network Tester";
	static NetworkTesterState* tester_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	static NetworkTesterState* getInstance();
};
#endif /* NETWORKTESTERSTATE_H_ */
