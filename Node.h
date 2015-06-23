/*
 * Node.h
 *@Author: James Child
 * Jan-April 2015
 */

#ifndef NODE_H_
#define NODE_H_
#include <string>
#include "EnumState.h"

#include "Statistics.h"
#include "PingObservable.h"
#include "Observer.h"
using namespace std;

/*
 * implements Observer
 */
class Node: public Observer{
private:
	string device_name;
	string ip_address;
	string device_type;
	WatchState watch_state;
	DeviceState device_state;
	Statistics *stats;

	/*
	 * get state number
	 */
	int get_int_watch();

public:
	Node(string name, string ip, string type);
	void virtual_no_response(string addr, string name);
	string virtual_ip_address();
	void virtual_is_responding();
	void virtual_being_watched();
	void update();
	void update_monitoring();
	void is_watch();
	void no_response();
	void not_watch();
	void is_responding();
	void watch();
	void end();
	string getName();
	string getip_address();
	string get_type();
	string get_stats();
	string getState();
	string getWatchState();
	string toString();
};
#endif /* NODE_H_ */
