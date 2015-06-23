/*
 * AllDevicesState.h
 *  Created on: Jan-April 2015
 *@Author: James Child
 */

#ifndef ALLDEVICESSTATE_H_
#define ALLDEVICESSTATE_H_

#include "MenuState.h"
using namespace std;

class AllDevicesState: public StateInterface{
private:
	string id = "3";
	string name = "View Network Devices";
	static AllDevicesState* view_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	//AllDevicesState();
	static AllDevicesState* getInstance();
};



#endif /* ALLDEVICESSTATE_H_ */
