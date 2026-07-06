//req_avg_temp.c: functions to return the average temperature for packets whose timestamps are within the requested time interval

#include <stdio.h>
#include "requests.h"

//print_average_temperature: print the average temperature over a given time interval
void print_average_temperature(SensorPacket *head, double t1, double t2) {
	double sum = 0.0;
	int count = 0;
	//loop through sensor packets
	for (SensorPacket *current = head; current != NULL; current = current->next){
		//check if sensor packet time is between t1 and t2
		if ( (current->time >= t1) && (current->time <= t2) ){
			sum += current->temperature; //add to sum
			count++;
		}
	}
	if (count > 0){
		//calculate the average temperature
		double avg = sum / count;
		printf("avg. temp: %.2f\n", avg);
	}
	else{ //if no reading in the givern time interval print 0.00
		printf("avg. temp: 0.00\n");
	}
}

