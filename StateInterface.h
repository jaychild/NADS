/*
 * StateinterfaceState.h
 * @Author: James Child
 * Jan-April 2015
 */

#ifndef STATEINTERFACE_H_
#define STATEINTERFACE_H_
#include <string>
#include "Controller.h"
using namespace std;

class StateInterface{
private:

public:
    Controller *con = Controller::getInstance();
    StateInterface();
    virtual string get_id();
    virtual string get_name();
    virtual string read_to_string();
    virtual void run_options();
    virtual ~StateInterface();
};


#endif /* STATEINTERFACE_H_ */
