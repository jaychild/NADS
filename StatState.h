/*
 * StatState.cpp
 * @Author: James Child
 * Jan-April 2015
 */

#ifndef STATSTATE_H_
#define STATSTATE_H_

#include "StateInterface.h"
using namespace std;
class StatState: public StateInterface{
private:
	string id = "4";
	string name = "Display Response Statistics";
	static StatState* stat_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();
public:
	static StatState* getInstance();
};
#endif /* STATSTATE_H_ */
