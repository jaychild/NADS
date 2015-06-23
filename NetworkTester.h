/*
 * NetworkTester.h
 *@Author: James Child
 * Jan-April 2015
 */

#ifndef NETWORKTESTER_H_
#define NETWORKTESTER_H_
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <unistd.h>		// Needed to close the connection
#include <iostream>
#include <vector>

using namespace std;
class NetworkTester{
private:
	static NetworkTester* singleton;
	string address = "www.google.co.uk";
	string port = "80";
	vector<int> *error_log;

public:
    static NetworkTester* getInstance( );

    int configure_tester(string addr, string prt);

    /*
     * checks network access using sockets
     */
    int check_network_connection();

    ~NetworkTester( );

private:


};



#endif /* NETWORKTESTER_H_ */
