#include <iostream>
#include <stdio.h>
#include <math.h>
///#include "lcgrand.h"  //Implementation rematining ###########################################
#include "simFunctions.h"

int num_custs_delayed, num_delays_required,
    next_event_type, num_events, num_in_queue,
    server_status; //state variables

float avg_num_in_q, avg_server_util, avg_interarrival,
    avg_service_time, sim_time, time_arrival[Q_LIMIT+1], 
    time_last_event, time_next_event[3],total_delays;
void initialize(){
	num_custs_delayed = 0;
	next_event_type = 1;
	num_events = 2;
	num_in_queue = 0;
	
	server_status = IDLE;
	sim_time = 0.0;
	time_last_event = 0.0;
	time_next_event[0] = sim_time + generator();
	time_next_event[1] = 1.0e30;


	avg_num_in_q = 0.0;
	avg_server_util = 0.0;
	time_arrival[Q_LIMIT + 1];
	total_delays = 0.0;

}

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
	fprintf(out, "\n\n\n\n\n\n This is a SINGLE SERVER QUEUE SIMULATION LOG:: \n\n");
	fprintf(out,"Given Average Interarrival Time is: %f\n",avg_interarrival);
	fprintf(out,"Given Average Service Time is: %f\n",avg_service_time);
	fprintf(out,"Required number of simulation runs: %d\n",num_delays_required);
	
	
	initialize(); //reset all state vars, statistical counters, and clock variables (incl time of last event)

	//keep running until the given number of delays not met
	while (num_custs_delayed < num_delays_required){
	  //updates 
	  timing();
	  
	  update_stats();
	  switch(next_event_type){
	  	case 1:
	  		arrive();
	  		break;

	  	case 2:
	  	  depart();
	  	  break;
	  }
	}
	//log to output.txt
	report();

	fclose(in);
	fclose(out);

	
	return 0;
}