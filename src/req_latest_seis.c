//req_latest_seis.c: functions to return the latest seismic reading

#include <stdio.h>
#include "requests.h"

//print_latest_seis: prints the latest seismic reading and its sensor id
void print_latest_seis(SensorPacket *head) {
	if (head == NULL) {
		return; //no sensor data to return
	}

	SensorPacket *latest  = head; //track sensor packet with largest timestamp
	
	for (SensorPacket *current = head->next; current != NULL; current = current->next) {
        if (current->time > latest->time) {
            latest = current;  
        }
    }
	printf("seis: %.2f (ID%d)\n", latest->seismic, latest->sensorid);
}
