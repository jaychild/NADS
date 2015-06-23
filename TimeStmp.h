/*
 * TimeStamp.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#ifndef TIMESTMP_H
#define	TIMESTMP_H
#include <string>
#include <future>		/* async thread */
#include <thread>
using namespace std;

class TimeStamp{
private:
    static TimeStamp* time_stamp_instance;
    char hours;
    char minutes;
    char seconds;    
    int years;
    char months;
    char days;
    
    struct tm times;
    mutex time_tex;     
    
    void thread_timer();    
public:   
    TimeStamp();
    static TimeStamp* getInstance();
    string getTime();
};

#endif	/* TIMESTMP_H */

