/*
 * EnumState.h
 * Created on: Jan-April 2015
 * @Author: James Child
 * Defines the possible monitoring states and device states
 */

#ifndef ENUMSTATE_H_
#define ENUMSTATE_H_
#include <string>
using namespace std;
enum class DeviceState{responding, unresponsive, delay, unknown};
enum class WatchState{active, inactive};
#endif /* ENUMSTATE_H_ */
