/*
 * Statistics.h
 * @Author: James Child
 * Jan-April 2015
 */
#include "Statistics.h"
#include "TimeStmp.h"
#include <stdlib.h>     /* atoi */
using namespace std;

Statistics::Statistics(){
	packets_sent = 0;
	packets_lost = 0;
	success_rate = 0;
        occurance = "";
        time = TimeStamp::getInstance();
}

/*
 * increments the sent packets field by 1
 */
void Statistics::increment_packets_sent(){
	packets_sent++;
}

/*
 * increments packets lost field by 1
 */
void Statistics::increment_packets_lost(){
	packets_lost++;
        occurance = time->getTime();
}

/*
 * calculates the percentage of received echo responses
 */
double Statistics::calculate_success_rate(){
	double a = (((double)packets_sent - packets_lost)/packets_sent)*100;
	return a;
}

/*
 * returns class as string
 */
string Statistics::toString(){
	success_rate = calculate_success_rate();
	if(success_rate<0)success_rate = 0; //stops negative problem
	string str_packets_sent = to_string(packets_sent);
	string str_packets_lost = to_string(packets_lost);
	string str_success_rate = to_string(success_rate);

	string out = ("\n   Packets Sent: " + str_packets_sent + "\n   Packets Lost: " +
			str_packets_lost + "\n   Success Rate: " + str_success_rate + "%" + "\n   Last No Response: " + 
                        occurance + "\n~~" +
			"                                         ~~");
	return out+"\n";
}



