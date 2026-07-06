//requests.h: Handles all the requests from control centre

#ifndef REQUESTS_H
#define REQUESTS_H

#include "memory.h"

//print_latest_temp: prints the latest temperature and its sensor id 
void print_latest_temp(SensorPacket *head);
//print_latest_seis: prints the latest seismic reading and its sensor id
void print_latest_seis(SensorPacket *head);
//print_max_seis: print the maximum seismic value
void print_max_seis(SensorPacket *head, double t1, double t2);
//print_average_temperature: print the average temperature over a given time interval
void print_average_temperature(SensorPacket *head, double t1, double t2);
//del_measuremnets: deletes all measurements from a particular sensor within a given time interval 
SensorPacket *del_measurements(SensorPacket *head, int id, double t1, double t2);

#endif
