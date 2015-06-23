/*
 * NetworkTester.cpp
 * Singleton Pattern
 *
 * Uses a socket connection to test the network
 * access of the system the program is running on.
 *
 * Singleton prevent multiple instances of the
 * network tester from being declared. Only one can
 * be created at runtime. This helps to manage
 * memory allocation, but also prevents multiple
 * socket connections from being declared.
 *
 *  Created on: Jan-April 2015
 *  @Author: James Child
 */

#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <unistd.h>		// Needed to close the connection
#include <iostream>
#include <vector>
#include "NetworkTester.h"
using namespace std;

/*
 * global static point that insures only one NetworkTester
 */
NetworkTester* NetworkTester::singleton = NULL;

/*
 * returns the instance of the class
 */
NetworkTester* NetworkTester::getInstance(){
   if (!singleton)   // Only allow one instance of class to be generated.
      singleton = new NetworkTester;
   return singleton;
}

/*
 * Changes the test host to another server of the users choice. Tests 
 * the connection first before changing- otherwise problems will follow.
 */
int NetworkTester::configure_tester(string addr, string prt){
    int error = 1;
    int connection=0;
    struct addrinfo host_;
    struct addrinfo *host__list;

    const char *test_address = addr.c_str();
    const char *test_port = prt.c_str();

    /*
     * doesn't specify ip format and sets stock stream for connection
     */
    memset(&host_, 0, sizeof host_); // x = size of host
    /*Sets the first x bytes of the value at host to 0 */
    host_.ai_family = AF_UNSPEC;
    host_.ai_socktype = SOCK_STREAM;
    /*
     * creates socket
     */
    connection = getaddrinfo(test_address, test_port, &host_, &host__list);

    /*
     * checks the result of the getaddrinfo
     */
    if (connection != 0){
	error = 0;
    }else{
	int raw_socket ;
   	raw_socket = socket(host__list->ai_family, host__list->ai_socktype,host__list->ai_protocol);
   	if (raw_socket == -1){
        	error = 2;
        }else {
            connection = connect(raw_socket, host__list->ai_addr, host__list->ai_addrlen);
            if (connection == -1){
                    error = 3;
            }else{
                    close(raw_socket);
            }
        }
    }

    if(error == 1){
	address = addr;
	port = prt;
    }
    return error;
}


/*
 * checks network access using sockets
 */
int NetworkTester::check_network_connection(){
    int error = 1;
    int connection=0;
    struct addrinfo host_;
    struct addrinfo *host__list;

    const char *test_address = address.c_str();
    const char *test_port = port.c_str();

    /*
     * doesn't specify ip format and sets stock stream for connection
     */
    memset(&host_, 0, sizeof host_);
    host_.ai_family = AF_UNSPEC;
    host_.ai_socktype = SOCK_STREAM;
    /*
     * creates socket
     */
    connection = getaddrinfo(test_address, test_port, &host_, &host__list);

    /*
     * checks the result of the getaddrinfo
     */
    if (connection != 0){
        error = 0;
    }else{
        int raw_socket ;
	raw_socket = socket(host__list->ai_family, host__list->ai_socktype,host__list->ai_protocol);
	if (raw_socket == -1){
            error = 2;
	}else {
            connection = connect(raw_socket, host__list->ai_addr, host__list->ai_addrlen);
            if (connection == -1){
                error = 3;
            }else{
                close(raw_socket);
            }
	}
    }
    return error;
}

