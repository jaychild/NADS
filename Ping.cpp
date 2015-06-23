/*
 * Ping.cpp
 * @Author: James Child
 * Jan-April 2015
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Ping.h"
using namespace std;

int out = 0;

/*
 * Ping object that takes the name and ip address of the device
 * that is to be pinged.
 * creates and initializes a PingReader object with the IP address
 * of the Node using composition.
 */
Ping::Ping(string host, string ip){
	host_name=host;
	ip_address=ip;
}

/*
 * -c does a packet count, a lot quicker this way -w specifies
 * a maximum time-out period
 */
void Ping::build_command(string addr){
	command = "ping -c 1 -w 1 " + addr + " >> " + addr + ".txt";
	//cout << "\nCommand: " << command << "\n";
}

void Ping::ping_node(){
	system((command).c_str());
}

