#include <iostream>
#include <string>
#include <cstring>
#include <future>		/* async thread */
#include <thread>
#include <pthread.h>
#include <sstream>      // std::stringstream
#include <thread>
#include <stdlib.h>     /* srand, rand */
#include "Controller.h"
#include "AllNodes.h"
#include "NetworkTester.h"
#include "PingObservable.h"
#include "FileManager.h"

#define MACRO test_data()
#define RANDMACRO random_data()

using namespace std;

/*
 * global static point that insures only one RemoveNodeState
 */
Controller* Controller::control_singleton = NULL;

/*
 * returns the instance of the class
 */
Controller* Controller::getInstance(){
   if (!control_singleton){ // Only allow one instance of class to be generated.
      control_singleton = new Controller();
   }
   return control_singleton;
}

Controller::Controller(){
	instance = NetworkTester::getInstance();
	an = AllNodes::getInstance();
	observable = new PingObservable();
	files = new FileManager();
	load_from_file("nrds.csv");
        //MACRO;
        //RANDMACRO;
}


/*
 * configures host used to check network connection
 */
int Controller::configure_test_host(string addr, string port){
	return instance->configure_tester(addr,port);
}

/*
 * loads from file
 */
void Controller::load_from_file(string file){
	string name, ip, type, lines_in;
	unsigned int no_of_lines = files->count_lines("nrds.csv");
	try{
                ifstream load_file(file);
		for(unsigned int i = 0; i<no_of_lines;i++){
			getline(load_file, name,',');
			getline(load_file, ip,',');
			getline(load_file, type);
                        if(check_ip_format(ip)==1)addNode(name,ip,type);
		}
		load_file.close();
	}catch(ifstream::failure e){
		cout << "\nFile Read Error";
	}
}


/*
 * Checks the internet connection using pipe-command
 * 0 = no internet
 * 1 = internet
 */
int Controller::check_connection(){
	int result = instance->check_network_connection();
	return result;
}

/*
 * Checks for IPv4 format   
 */
int Controller::check_ip_format(string ip){
	char dot;
        unsigned int octlet_a,octlet_b,octlet_c,octlet_d, result = 0;
        string ip_check;
        string check[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};   
        string upper[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","sS","T","U","V","W","X","Y","Z"};
        string special[25] = {"¬","!","£","$","%","^","&","*","(",")","_","+","}","{","~","@",":",">","?","<","|","`","\""," ","/"};
	stringstream stream(ip);
        stream >> ip_check;
        for(unsigned int i = 0; i<24;i++){
             string t = check[i];
             string u = upper[i];
             string s = special[i];
            if((ip_check.find(t)!= string::npos)||(ip_check.find(u) != string::npos)||(ip_check.find(s) != string::npos)){
                //cout << "Found Something:" << t << endl;
                result++;
            }             
        }/*checks for alphabet*/      
        stringstream new_stream(ip);
     
        new_stream >> octlet_a >> dot >> octlet_b >> dot >> octlet_c >> dot >> octlet_d;
     
	        
	if(octlet_a<256)result++;
	if(octlet_b<256)result++;
	if(octlet_c<256)result++;
	if(octlet_d<256)result++;  

	if(result==4){
		result = 1;
	}else{
		result = 0;
	}
	return result;
}

/*
 * Adds a network device to the system
 */
int Controller::addNode(string device_name, string ip_address, string type){
	Node *obj = new Node(device_name,ip_address, type);
	cmtx.lock();
	int result =an->addNode(obj);
	observable->attach(obj);
	cmtx.unlock();
	return result;
}

/*
 * removes a network device from the system
 */
int Controller::removeNode(string ip_address){
	int result = an->remove(ip_address);
	observable->detach(ip_address);
	return result;
}

/*
 * Lists all network devices added to the
 * system
 */
string Controller::listNodes(){
	string string_of_nodes = an->getNodes();
	return string_of_nodes;
}

/*
 * Returns all information of a particular
 * network device.
 */
string Controller::getNodeDetails(string ip){
	string details = an->getNodeState(ip);
	return "";
	//implementation
}

/*
 * Starts the monitoring process of a particular
 * network device
 *
 * 0 = no connection
 * 1 = connection
 */
int Controller::watchNode(){
	observable->set_monitoring_state(1);
	observable->start_monitoring_state();
	return 0;
}

/*
* spawns the thread for the monitoring process
 */
void Controller::thread_watch(){
	std::thread first_thread(&Controller::watchNode,this);
	first_thread.detach();
}

/*
 * Cancels the monitoring process of a particular
 * network device
 */
void Controller::cancelWatch(){
	observable->set_monitoring_state(0);
}

/*
 * Gets statistics of downtime of all network devices
 * monitored during the current session. This information
 * can be saved to CSV file if required.
 */
string Controller::getStatistics(){
	string out= an->getStats();
	return out;
}

/*
 * Shows the current watch state of a particular network
 * device.
 */
void Controller::save_state(){
	an->save_state();
}

/*
* Returns 1 if monitoring 0 if not
*/
int Controller::isMonitoring(){
    observable->isMonitoring();
}

/****************************MACRO FUNCTIONS****************************/

/*
 * Test Method, used for macro testing
 */
void Controller::test_data(){
    string a =  "192.168.0.12";
    string b =  "192.168.0.12";
    string cd = "192.168.0.8";
    string d = "FE80:0000:0000:0000:0202:B3FF:FE1E:8329";
    string e =  "....";
    string f = "www.apache.co.uk";
    string g = "My-dc01";
    string h = "*&^%^&";
    string i = "255255255255";
    string j = "£.£.£.£";
    string k = "0.0.0.0";
    string l = "t.t.t.t";
    string m = "1.2.3.d";
    string n = "1.2.3.*";    
    
    if(check_ip_format(a)==1) addNode("t1",a,"a"); 
    if(check_ip_format(b)==1) addNode("t2",b,"a");  
    if(check_ip_format(cd)==1)addNode("t3",cd,"a");  
    if(check_ip_format(d)==1) addNode("t4",d,"a");  
    if(check_ip_format(e)==1) addNode("t5",e,"a");  
    if(check_ip_format(f)==1) addNode("t6",f,"a");  
    if(check_ip_format(g)==1) addNode("t7",g,"a");  
    if(check_ip_format(h)==1) addNode("t8",h,"a");  
    if(check_ip_format(i)==1) addNode("t9",i,"a");  
    if(check_ip_format(j)==1) addNode("t10",j,"a");  
    if(check_ip_format(k)==1) addNode("t11",k,"a");  
    if(check_ip_format(l)==1) addNode("t12",l,"a");  
    if(check_ip_format(m)==1) addNode("t13",m,"a");  
    if(check_ip_format(n)==1) addNode("t14",n,"a");     
}

void Controller::random_data(){
    string random[88]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
                       "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","sS","T","U","V","W","X","Y","Z",
                       "¬","!","£","$","%","^","&","*","(",")","_","+","}","{","~","@",":",">","?","<","|","`",".","1","2","3",
                       "4","5","6","7","8","9","0"," ","\"","/"};
    srand (time(NULL));
    int x = rand() % 50+1; 
    int arrayx = 0;
    double success = 0;
    string ax;
    for(unsigned int ix = 0; ix<10000 ;ix++){        
        for(unsigned int ixx = 0; ixx<x;ixx++){
            arrayx = rand() % 86;
            ax.append(random[arrayx]);             
        }
        if(check_ip_format(ax)==1){
            addNode("t1",ax,"a");   
            success++;
        }        
        //cout << ax << endl;
        ax="";
        //usleep(1000);   
        x = rand() % 50+1;
    }  
    cout << "Success Rate:" << success << " of 10000" << endl;
    usleep(5000000);
}



