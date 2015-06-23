#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <future>		/* async thread */
#include <thread>


#include "ErrorMessager.h"
using namespace std;
string buffer;

ErrorMessager::ErrorMessager(){
}/*blank constructor*/

void ErrorMessager::update(){
	if(update_toggle==0){
		update_toggle = 1;
		string title = "Notice: ";
		string message = "\"Stopped Monitoring\"";
		system(("notify-send " + title + message).c_str());
	}
}/*@Override*/

/*
 * @override
 */
void ErrorMessager::update_monitoring(){
	if(update_toggle==1){
		update_toggle = 0;
		string title = "Notice: ";
		string message = "\"Now Monitoring\"";
		system(("notify-send " + title + message).c_str());
	}
}/*@Override*/

void ErrorMessager::virtual_no_response(string addr, string name){
    string message = "\"" + name + " No response"  + "\"";
    if(buffer!=addr){
        //system(("notify-send" + addr + " " + message).c_str());
        system(("notify-send " + name + ":" + addr + " -u critical " +"\"Not Responding\"").c_str()); 
        buffer = addr;
    }    
}/*@Override*/

void ErrorMessager::virtual_being_watched(){
	string title = "Notice";
	string message = "\"Now Monitoring\"";
	system(("notify-send " + title + message).c_str());
}/*@Override*/

/*
 * Checks the internet connection using pipe-command
 * 0 = no internet
 * 1 = internet
 */
int ErrorMessager::connectivity_error(){
	string error = "\"No Network Access\"";
	system(("notify-send " + error+ " \"Watch Process Stopped\"").c_str());
	return 1;
}

void ErrorMessager::clear_buffer(){
    buffer = "";
}/*@Override*/
