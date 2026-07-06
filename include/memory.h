//memory.c: functions to allocate and initialize sensor packets on the heap

#ifndef MEMORY_H
#define MEMORY_H

#include "message.h"

//create_new_node: create a new node for each sensor packet 
SensorPacket *create_new_node(int sensorid, double time, double temperature, double seismic);
//append_sensor_data: add new sensor packet to end of list
SensorPacket *append_sensor_data(SensorPacket *head,int sensorid, double time, double temperature, double seismic);
//free_list: free all the nodes in list 
void free_list (SensorPacket *head);

#endif
