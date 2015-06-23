/*
 * TimeStamp.cpp
 * @Author: James Child
 * Jan-April 2015
 */
#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <future>		/* async thread */
#include <thread>
#include <unistd.h>
#include <cstring>
#include <iomanip>
#include "TimeStmp.h"
using namespace std;
TimeStamp* TimeStamp::time_stamp_instance=NULL;

TimeStamp::TimeStamp(){
    hours=0;
    minutes=0;
    seconds=0;
}

TimeStamp* TimeStamp::getInstance(){
    if(!time_stamp_instance){
        time_stamp_instance = new TimeStamp();
    }
    return time_stamp_instance;
}


/*
 * returns the formatted time
 * 
 */
string TimeStamp::getTime(){
    time_t t = time(NULL);
    struct tm *a_time = localtime(&t);

    hours = a_time->tm_hour;
    minutes = a_time->tm_min;
    seconds = a_time->tm_sec;
    
    days = a_time->tm_mday;
    months = a_time->tm_mon;
    years = a_time->tm_year;
    
    char buff[1024];
    sprintf(buff,"%02i:%02i:%02i - %02i/%02i/%02d",hours,minutes,seconds,days,months+1,years+1900);  
    return buff;
}
        
