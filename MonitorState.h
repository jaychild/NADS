/*
 * MonitorState.h
 * Created: Jan-April 2015
 *@Author: James Child
 */

#ifndef MONITORSTATE_H_
#define MONITORSTATE_H_
#include "StateInterface.h"

using namespace std;
class MonitorState: public StateInterface{

private:
	string id = "5";
	string name = "Monitor Network Devices";
	static MonitorState* watch_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	static MonitorState* getInstance();
};
#endif /* MONITORSTATE_H_ */
