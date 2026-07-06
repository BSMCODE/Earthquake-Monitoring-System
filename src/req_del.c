//req_del.c: functions to remove all sensor packet nodes for a given sensor id and time interval upon request. 	

#include <stdio.h>
#include <stdlib.h>
#include "requests.h"

//del_measuremnets: deletes all measurements from a particular sensor within a given time interval 
SensorPacket *del_measurements(SensorPacket *head, int id, double t1, double t2) {
	SensorPacket *previous = NULL;
	SensorPacket *current = head;
	while (current != NULL) {
		//check if sensor packet's ID and time match the given request
		if ( (current->sensorid == id) && ((current->time >= t1) && (current->time <= t2)) ) {
			if (previous == NULL){
				head = current->next; //deletion at the head, and new head is the next node
			}
			else {
				previous->next = current->next; //deletion at the middel or end, and bridge the previous to current->next
			}
			//free the deleted node 
			SensorPacket *to_remove = current;
			current = current->next;
			free(to_remove);
		}
		else {
			previous = current;
			current = current->next;
		}
	}
	return head;
}

