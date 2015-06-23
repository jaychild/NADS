/*
 * LiveState.h
 * Created: Jan-April 2015
 *@Author: James Child
 */

#ifndef LIVESTATE_H
#define	LIVESTATE_H
#include "MenuState.h"
using namespace std;

class LiveState: public StateInterface{
private:
    	string id = "10";
	string name = "Terminal Monitor Mode";
	static LiveState* live_singleton;
	virtual string get_id();
	virtual string get_name();
	virtual void run_options();        
public:
	static LiveState* getInstance();    
};
#endif	/* LIVESTATE_H */

