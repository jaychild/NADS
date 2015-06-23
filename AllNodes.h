/*
 * AllNodes.h
 *  Created on: Jan-April 2015 
 * Collection class, containing all Node objects. 
 *@Author: James Child
 */

#ifndef ALLNODES_H_
#define ALLNODES_H_
#include <string>
#include <vector>
#include "Node.h"
#include "FileManager.h"
using namespace std;

class AllNodes: public Observer{
private:
	static AllNodes* allnodes_singleton;
        FileManager *fm;// = new FileManager();
        vector<Node*> nodes;
	std::mutex anmtx;             // mutex for critical section
        
protected:
    AllNodes();

public:
	int get_collection_size();

	static AllNodes* getInstance( );

	/*
	 * returns a Node object from the nodes vector, using its IP
	 * address.
	 */
	Node getNodeObject(string ip);


	int addNode(Node *obj);

	/*
	 * gets node object by position
	 */
	Node get_node_object(int pos);

	/*
	 * removes a Node object from the vector
	 * allNodes
	 */
	int remove(string name);

	/*
	 * returns 1 is a device object with string ip exists in
	 * nodes.
	 * returns 0 otherwise.
	 */
	int isDevice(string ip);

	/*
	 * returns the string of a particular nodes state.
	 * if the node doesn't exist, it returns "error".
	 */
	string getNodeState(string ip);

	/*
	 * return all nodes
	 */
	string getNodes();

	/*
	 * saves the state of the program
	 */
	void save_state();

	/*
	 * returns the Statistics information for all devices
	 */
	string getStats();
};

#endif /* ALLNODES_H_ */
