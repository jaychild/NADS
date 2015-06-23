/*
 * RemoveNodeState.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#ifndef REMOVENODESTATE_H_
#define REMOVENODESTATE_H_

#include "MenuState.h"
using namespace std;
class RemoveNodeState: public StateInterface{
private:
	string id = "2";
	string name = "Remove Node";
	static RemoveNodeState* remove_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();
public:
	static RemoveNodeState* getInstance();
};
#endif /* REMOVENODESTATE_H_ */
