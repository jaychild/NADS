/*
 * HeloState.cpp
 * Created: Jan-April 2015
 *@Author: James Child
 */
#include "HelpState.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * global static point that insures only one HelpState
 */
HelpState* HelpState::help_singleton = NULL;

/*
 * returns the instance of the class
 */
HelpState* HelpState::getInstance(){
   if (!help_singleton) // Only allow one instance of class to be generated.
      help_singleton = new HelpState();
   return help_singleton;
}


string HelpState::get_id(){
	return id;
}
string HelpState::get_name(){
	return name;

}
void HelpState::run_options(){
	system("clear");
	cout << "                        Help and Information\n" << endl;
	cout << "[Add Network Device]" << endl;
	cout << "       Takes the device name, IP address (ipv4) and device type as" << endl;
	cout << "       parameters to create a device instance. The IP address must" << endl;
	cout << "       be correct, otherwise the application will register it as un-"<< endl;
	cout << "       responsive.\n"<< endl;

	cout << "[Remove Network Device]" << endl;
	cout << "       Removes a configured network device from the application. Takes" << endl;
	cout << "       the IP address (ipv4) as a single argument and removes if it " << endl;
	cout << "       exists.\n" << endl;

	cout << "[View Network Devices]" << endl;
	cout << "       Returns all added network devices and displays the connection" << endl;
	cout << "       state and monitoring state.\n " << endl;

	cout << "[Display Response Statistics]" << endl;
	cout << "       Returns the number of echo responses recieved, echo responses " << endl;
	cout << "       lost and the response percentage for each configured network " << endl;
	cout << "       device. Low response percentage suggests a problem with the specific " << endl;
	cout << "       network device.\n" << endl;

	cout << "[Monitor Network Devices]" << endl;
	cout << "       Monitors every configured network device in the background. " << endl;
	cout << "       Additional devices can be added during this process- however, " << endl;
	cout << "       they will be monitored automatically.\n" << endl;

	cout << "[Stop Monitoring Devices]" << endl;
	cout << "       Ends the monitoring process\n" << endl;

	cout << "[Configure Network Tester]" << endl;
	cout << "       This application establishes a socket connection to a Webserver " << endl;
	cout << "       in order to establish network access. By default, this application "<<endl;
	cout << "       connects to the Google Webserver, however, can be configured to " << endl;
	cout << "       connect to a different server via its IP address and Port Number. " << endl;
	cout << "       [Note]the server must be configured to allow socket connections to " << endl;
	cout << "       the specified port and respond to them. If this isn't allowed, the "<<endl;
	cout << "       application will assume no network activity and not allow the " << endl;
	cout << "       monitoring process to start.\n" << endl;

	cout << "[Save Configuration]" << endl;
	cout << "       Saves all configured network devices to a .csv file. This application"<<endl;
	cout << "       automatically loads network_save_file.csv on start up, if correctly "<<endl;
	cout << "       formatted. The save/ load format is: name,ip,type\n"<<endl;

	cout<< "\nPress return to continue" << endl;
	cin.ignore();
}/*if only there was a way for the computer to generate its own help.....*/



