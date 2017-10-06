#include <iostream>
#include <stdio.h>
#include <math.h>
///#include "lcgrand.h"  //Implementation rematining ###########################################
#include "simFunctions.h"
#define Q_LIMIT 100  //maximum customers in allowed in queue
#define BUSY 1						//server busy
#define IDLE 0						//server idle


int num_custs_delayed, num_delays_required,
    next_event_type, num_events, num_in_queue,
    server_status; //state variables

float avg_num_in_q, avg_server_util, avg_interarrival,
    avg_service_time, sim_time, time_arrival[Q_LIMIT+1], 
    time_last_event, time_next_event[3],total_delays;

FILE *in, *out;
// declare non simlib functions:

using namespace std;
int main(){
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	//only arrive and depart events
	num_events = 2;
	//load the user defined interarrival, simulation number, service time into global vars
	fscanf(in,"%f %f %d", &avg_interarrival, &avg_service_time, &num_delays_required);
	initialize();
	
	return 0;
}