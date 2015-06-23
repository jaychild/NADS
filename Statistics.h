/*
 * Statistics.h
 * @Author: James Child
 * Jan-April 2015
 */
#ifndef STATISTICS_H_
#define STATISTICS_H_
#include <string>
#include "TimeStmp.h"
using namespace std;
class Statistics{
private:
	int packets_sent;
	int packets_lost;
	int success_rate;
        string occurance;
        TimeStamp *time;
public:
	Statistics();
	void increment_packets_sent();
	void increment_packets_lost();
	double calculate_success_rate();
	string toString();
};
#endif /* STATISTICS_H_ */
