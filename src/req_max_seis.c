//req_max_seis.c: function to reurn the maximum seismic value recorded within a requested time interval

#include <stdio.h>
#include "requests.h"

//print_max_seis: print the maximum seismic value
void print_max_seis(SensorPacket *head, double t1, double t2) {
	int found = 0; //track whether at least one sensor packer mathces the given time frame
	double max_seis = 0.0;
	int max_id = -1;

	for (SensorPacket *current = head; current != NULL; current = current->next) {
		if ( (current->time >= t1) && (current->time <= t2) ) {
			if ( (!found) || (current->seismic > max_seis) ) {
				found = 1;
				max_seis = current->seismic;
				max_id = current->sensorid;
			}
		}
	}
	if (found) {
		printf("max. seis: %.2f (ID%d)\n", max_seis, max_id);
	}
}
