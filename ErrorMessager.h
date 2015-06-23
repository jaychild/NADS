/*
 * ErrorMessager.h
 * Created on: Jan-April 2015
 * @Author: James Child
 * Defines the ErrorMessage class. This is used to generate notifications
 * Probably should have a better name!
 */

#ifndef ERRORMESSAGER_H_
#define ERRORMESSAGER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <future>		/* async thread */
#include <thread>
#include "Observer.h"

using namespace std;

class ErrorMessager: public Observer{
private:
	int update_toggle = 1;
        mutex err_mtx;

public:
	ErrorMessager();

	void update();

	void update_monitoring();

	void virtual_no_response(string addr, string name);

	void virtual_being_watched();

	int connectivity_error();

	void no_response(string name, string ip);
        
        void virtual clear_buffer();
};
#endif /* ERRORMESSAGER_H_ */
