//memory.c: functions to allocate and initialize sensor packets on the heap

#include <stdlib.h>
#include "memory.h"

//create_new_node: create a new node for each sensor packet 
SensorPacket *create_new_node(int sensorid, double time, double temperature, double seismic) {

	SensorPacket *new_node = (SensorPacket*)malloc(sizeof(SensorPacket));
	//check for out of memory
	if (new_node == NULL){
		exit(1);
	}
	new_node->sensorid = sensorid;
	new_node->time = time;
	new_node->temperature = temperature;
	new_node->seismic = seismic;
	new_node->next = NULL;
	return new_node;
}

//append_sensor_data: add new sensor packet to end of list
SensorPacket *append_sensor_data(SensorPacket *head,int sensorid, double time, double temperature, double seismic){

	//create new node on the heap
	SensorPacket *new_node = create_new_node(sensorid, time, temperature, seismic);

	//if list is empty
	if (head == NULL){
		head = new_node;
		return head;
	}

	//traverse through list and append the new node to the end of list
	SensorPacket *current = head;
	while (current->next != NULL){
		current = current->next;
	}
	current->next = new_node;
	return head;
}

//free_list: free all the nodes in list 
void free_list(SensorPacket *head){
    SensorPacket *current = head;
    while(current !=NULL) {
        SensorPacket *to_remove = current;
        current = current->next;
        free(to_remove);
    }
}



