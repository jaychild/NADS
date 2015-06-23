/*
 * SaveState.cpp
 * @Author: James Child
 * Jan-April 2015
 */

#ifndef SAVESTATE_H_
#define SAVESTATE_H_
#include "StateInterface.h"
using namespace std;
class SaveState: public StateInterface{
private:
	string id = "8";
	string name = "Save Configuration";
	static SaveState* save_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();
public:
	static SaveState* getInstance();
};
#endif /* SAVESTATE_H_ */
