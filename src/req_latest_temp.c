//req_latest_temp.c: function to return the latest temperature 

#include <stdio.h>
#include "requests.h"

//print_latest_temp: prints the latest temperature and its sensor id 
void print_latest_temp(SensorPacket *head) {
	if (head == NULL) {
		return; //no data to return
	}

    SensorPacket *latest = head;//track sensor packet with largest time stamp

    for (SensorPacket *current = head->next; current != NULL; current = current->next) {
        if (current->time > latest->time) {
            latest = current; 
        }
    }
	printf("temp: %.2f (ID%d)\n", latest->temperature, latest->sensorid);
}
