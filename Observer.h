/*
 * Observer.h
 *@Author: James Child
 * Jan-April 2015
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "EnumState.h"
#include <iostream>
#include <string>
using namespace std;

class Observer{
public:
	virtual void update();
	virtual void update_monitoring();
	virtual string  virtual_ip_address();
	virtual void virtual_no_response(string addr, string name);
	virtual void virtual_is_responding();
	virtual void virtual_being_watched();
	virtual string toString();
        virtual void clear_buffer();
};



#endif /* OBSERVER_H_ */
