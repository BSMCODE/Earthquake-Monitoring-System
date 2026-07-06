//main.c: function to read lines from stdin and print output accordingly 

#include <stdio.h>
#include <string.h>

#include "message.h"
#include "requests.h"
#include "memory.h"

#define MAX_LENGTH 256

int main(void) {

	char line[MAX_LENGTH];
	SensorPacket *head = NULL;
	while ( fgets(line, MAX_LENGTH, stdin) != NULL ) {
		//check for sensor packet input
		if (line[0] == '#') {
        	int sensorid;
        	double time, temperature, seismic;
        	int match = sscanf(line, "#ID%d,time:%lf,temp:%lf,seis:%lf", &sensorid, &time, &temperature, &seismic);
		
			if (match == 4) {
				//append data in the heap
				head = append_sensor_data(head, sensorid, time, temperature, seismic);
			}
		}
		//check for request input
		else if (line[0] == '*') { 
			if ( strncmp(line, "*send_latest_temp", 16) == 0 ) {
				//print the latest temperature 
				print_latest_temp(head);
			}

			else if ( strncmp(line, "*send_latest_seis", 16) == 0 ){
				//print the latest seismic data
				print_latest_seis(head);
			}

			else if ( strncmp(line, "*send_average_temp", 18) == 0 ) {
				double t1, t2;
				if ( sscanf(line, "*send_average_temp,%lf,%lf", &t1, &t2) == 2 ) {
					//print average temperature
					print_average_temperature(head, t1, t2);
				}
			}

			else if ( strncmp(line, "*send_max_seis", 14) == 0){
				double t1, t2;
				if ( sscanf(line, "*send_max_seis,%lf,%lf", &t1, &t2) == 2 ){
					//call function to calculate teh max seis activity
					print_max_seis(head, t1, t2);
				}
			}

			else if ( strncmp(line, "*del_measurements", 17) == 0 ) {
				double t1, t2;
				int id;
				if ( sscanf(line, "*del_measurements,%d,%lf,%lf", &id, &t1, &t2) == 3) {
					//delete measuremnets
					head = del_measurements(head, id, t1, t2);					
				}
			}

			else if ( strncmp(line, "*shutdown", 9) == 0 ){
				free_list(head);
				return 0;
			}
		}	
	}

	//free the memory
	free_list(head);
	return 0;
}






