/*
 * StateinterfaceState.cpp
 * @Author: James Child
 * Jan-April 2015
 */

#include <string>
#include <iostream>
#include <algorithm>	/* erase, remove, begin, end*/
#include "StateInterface.h"
using namespace std;

StateInterface::StateInterface(){
}

string StateInterface::get_id(){

}
string StateInterface::get_name(){

}
string StateInterface::read_to_string(){
	string in;
        getline(cin, in);
	in.erase(remove(in.begin(),in.end(),' '),in.end());
	return in;
}

void StateInterface::run_options(){

}

StateInterface::~StateInterface(){

}


