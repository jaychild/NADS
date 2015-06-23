/*
 * EndState.h
 * Created on: Jan-April 2015
 * @Author: James Child * 
 * Defines the Stop Monitoring State
 */

#ifndef ENDSTATE_H_
#define ENDSTATE_H_

#include "StateInterface.h"

using namespace std;

class EndState: public StateInterface{

private:
	string id = "6";
	string name = "Stop Monitoring Devices";
	static EndState* end_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();

public:
	static EndState* getInstance();

};
#endif /* ENDSTATE_H_ */
