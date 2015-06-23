
/*
 * Node.cpp
 *@Author: James Child
 * Jan-April 2015
 */
#include <iostream>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <stdlib.h>     /* atoi */
#include <iomanip>

/* Related Classes */
#include "Node.h"
#include "EnumState.h"
#include "Statistics.h"
#include "Observer.h"
using namespace std;
mutex state_mutex;

/*
 * Node constructor
 */
Node::Node(string name, string ip, string type){
	device_name = name;
	ip_address = ip;
	device_type = type;
	watch_state = WatchState::inactive;
	device_state = DeviceState::unknown;
	stats = new Statistics();
	//obs->attach(this);
}

void Node::update(){
	watch_state = WatchState::inactive;
	device_state = DeviceState::unknown;
}

void Node::update_monitoring(){
	watch_state = WatchState::active;
}

/*
 * gets the device state of the observer
 * @override method, avoided the need to make another
 * method to modify the stats and then call them.
 * reduced coupling and method stack in one!
 */
void Node::virtual_no_response(string addr, string name){
	device_state = DeviceState::unresponsive;
	stats->increment_packets_sent();
	stats->increment_packets_lost();
}

/*
 * returns the ip address of the node
 */
string Node::virtual_ip_address(){
	return ip_address;
}
/*
 * @override method, avoided the need to make another
 * method to modify the stats and then call them.
 * reduced coupling and method stack in one!
 */
void Node::virtual_is_responding(){
	device_state = DeviceState::responding;
	stats->increment_packets_sent();
}

void Node::virtual_being_watched(){
	watch_state = WatchState::active;
}

/*
 * changes watch state to active
 */
void Node::is_watch(){
	watch_state = WatchState::active;
}

/*
* set response to unresponsive
*/
void Node::no_response(){
	device_state = DeviceState::unresponsive;
}

/*
 * changes watch state to active
 */
void Node::not_watch(){
	watch_state = WatchState::inactive;
	device_state = DeviceState::unknown;
}

/*
 * set response to unresponsive
 */
void Node::is_responding(){
	device_state = DeviceState::responding;
}

/*
 * Returns the nodes name
 */
string Node::getName(){
	return device_name;
}

/*
 * Returns IP address of node
 */
string Node::getip_address(){
	return ip_address;
}

/*
 * Returns type of the node
 */
string Node::get_type(){
	return device_type;
}

/*
 * gets the associated statistics information of the device
 */
string Node::get_stats(){
	return device_name + ": " +  stats->toString();
}

/*
 * returns the state of the network device;
 * Either Responding, Unresponsive, DelayedResponse - inherited
 * from the Enum class.
 */
string Node::getState(){
	string string_state;
  switch (device_state){
  	  case DeviceState::responding: string_state="Responding";break;
  	  case DeviceState::unresponsive: string_state="Unresponsive";break;
  	  case DeviceState::delay: string_state="Delayed Response";break;
  	  case DeviceState::unknown: string_state="Unknown";break;
  	  default: string_state="Error: Unrecognised state";break;
  }
  return string_state;
}

/*
 * returns watch state of the node
 */
string Node::getWatchState(){
	string string_watch;
	state_mutex.lock();
	switch(watch_state){
	 	 case WatchState::active: string_watch="Watch Active";break;
	 	 case WatchState::inactive: string_watch="Not Being Watched";break;
	 	 default: string_watch="Error: Unrecognised watch state";break;
	}
	state_mutex.unlock();
	return string_watch;
}

/*
 * returns a string representation of the node object
 */
string Node::toString(){
	return "\nDevice: [" + device_name + "]      IP Address : [" +
			ip_address + "]      Device Type: [" + device_type + "] \nState : [" +
			getState() + "]     Watch State: [" + getWatchState() +"]\n~~" +
			"                                                                                    ~~";
}






