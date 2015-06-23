/*
 * Ping.h
 *@Author: James Child
 * Jan-April 2015
 */

#ifndef PING_H_
#define PING_H_
#include <string>
using namespace std;
class Ping{
private:
	string host_name;
	string ip_address;
	string command;
public:
	Ping(string host, string ip);
	void build_command(string addr);
	void ping_node();
};
#endif /* PING_H_ */
