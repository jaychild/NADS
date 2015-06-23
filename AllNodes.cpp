#include <string>
#include <vector> 		/* vector array */
#include <iostream>

#include <future>		/* async thread */
#include <thread>
#include <pthread.h>
#include <fstream> 		/*file stream stuff */

#include "AllNodes.h"
#include "Node.h"

using namespace std;
AllNodes* AllNodes::allnodes_singleton = NULL;


/*
 * returns the instance of the class, or creates the
 * singleton instance of the AllNodes class
 */
AllNodes* AllNodes::getInstance(){
   if (!allnodes_singleton)  // Only allow one instance of class to be generated.
	   allnodes_singleton = new AllNodes;
   return allnodes_singleton;
}

/*
 *Constructor
 */
AllNodes::AllNodes(){
    fm = new FileManager();
}

/* SETTERS */

/*
 * Adds a node when passed a Node object by
 * the controller
 */
int AllNodes::addNode(Node *obj){
	string addr = obj->getip_address();
	int exists = isDevice(addr);
	if(exists==0){
		anmtx.lock();
		nodes.push_back(obj);
		anmtx.unlock();
	}
	return exists;
}

/*
 * remove() implementation
 */
int AllNodes::remove(string ip){
	int exists = isDevice(ip);
	if(exists==1){
		for(unsigned int i = 0; i<nodes.size(); i++){
			Node *a = nodes[i];
			anmtx.lock();
			string temp_ip = a->getip_address();
			anmtx.unlock();
			if(temp_ip==ip){
				anmtx.lock();
				nodes.erase(nodes.begin()+i);
				anmtx.unlock();
			}
		}
	}
	return exists;
}

/*
 * saves the state of the program
 */
void AllNodes::save_state(){
	FileManager *f = new FileManager();
	f->delete_save_file();
	string ip_address, name, type;
	for(unsigned int i = 0; i<nodes.size();i++){
		Node *n = nodes[i];
		name = n->getName();
		ip_address = n->getip_address();
		type = n->get_type();
		f->write_file(name, ip_address,type);
	}
}

/* GETTERS */

/*
 * returns 1 is a device object with string ip exists in
 * nodes.
 * returns 0 otherwise.
 */
int AllNodes::isDevice(string ip){
	int exists = 0;
	for(unsigned int i = 0; i < nodes.size(); i++){
		anmtx.lock();
		Node *node = nodes[i];
		anmtx.unlock();
		string s = node->getip_address();
		if((node->getip_address())==ip){
			exists = 1;
		}
	}
	return exists;
}

/*
 * returns the size of the nodes Vector
 */
int AllNodes::get_collection_size(){
	return nodes.size();
}

/*
 * gets node object by position
 */
Node AllNodes::get_node_object(int pos){
	return *nodes[pos];
}

/*
 * returns the string of a particular nodes state.
 * if the node doesn't exist, it returns "error".
 */
string AllNodes::getNodeState(string ip){
	int exists = isDevice(ip);
	string state = "error";
	Node *n;
	if(exists==1){
		state=n->getState();
	}
	return state;
}

/*
 * returns all nodes to a string.
 */
string AllNodes::getNodes(){
	string string_of_nodes = "";
	for(unsigned int i; i < nodes.size(); i++){
		anmtx.lock();
		Node *n = nodes[i];
		string_of_nodes+=n->toString();
		anmtx.unlock();
	}
	return string_of_nodes;
}

/*
 * returns the Statistics information for all devices
 * could this be implemented better?
 */
string AllNodes::getStats(){
	string out = "";
	for(unsigned int i = 0; i<nodes.size();i++){
		anmtx.lock();
		Node *n = nodes[i];
		anmtx.unlock();
		out+=n->get_stats();
	}
	return out;
}







