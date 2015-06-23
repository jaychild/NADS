#include <future>		/* async thread */
#include <thread>
#include <pthread.h>

#include <iostream>
#include "AllNodes.h"
#include "NetworkTester.h"
#include "PingObservable.h"
#include "FileManager.h"
using namespace std;

/*
 * Controller Class
 * @author James Child
 * Jan-April 2015 
 * Provides UI classes control over the model, whilst
 * removing tight coupling. 
 */
class Controller{
private:
	static Controller* control_singleton;
        
	mutex cmtx;
	AllNodes *an;// = AllNodes::getInstance();
	NetworkTester *instance;// = NetworkTester::getInstance();
	FileManager *files;
	PingObservable *observable;
        
        
protected:       
            
        /*
	 * Constructor
	 */
	Controller();
        void test_data();
        void random_data();

public:
	static Controller* getInstance();
	/*
	 * configures host used to check network connection
	 */
	int configure_test_host(string addr, string prt);

	/*
	 * loads from file
	 */
	void load_from_file(string file);

	/*
	 * Checks the internet connection using pipe-command
	 */
	int check_connection();

	/*
	 * Checks the internet connection using pipe-command
	 */
	int check_ip_format(string ip);

	/*
	 * Adds a network device to the system
	 */
	int addNode(string device_name, string ip_address, string type);

	/*
	 * removes a network device from the system
	 */
	int removeNode(string ip_address);

	/*
	 * Lists all network devices added to the
	 * system
	 */
	string listNodes();

	/*
	 * Returns all information of a particular
	 * network device.
	 */
	string getNodeDetails(string ip);

	/*
	 * Starts the monitoring process of a particular
	 * network device
	 */
	int watchNode();

	/*
	 * spawns the thread for the monitoring process
	 */
	void thread_watch();

	/*
	 * Cancels the monitoring process of a particular
	 * network device
	 */
	void cancelWatch();

	/*
	 * Gets statistics of downtime of all network devices
	 * monitored during the current session. This information
	 * can be saved to CSV file if required.
	 */
	string getStatistics();

	/*
	 * Shows the current watch state of a particular network
	 * device.
	 */
	void getWatchState();

	/*
	 * Shows the current watch state of a particular network
	 * device.
	 */
	void save_state();

	/*
	 * Shows the current watch state of a particular network
	 * device.
	 */
	void load_state();
        
        /*
         * Returns 1 if monitoring 0 if not
         */
        int isMonitoring();
};
