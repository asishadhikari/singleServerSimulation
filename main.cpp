#include <iostream>
#include <stdio.h>
#include <math.h>
///#include "lcgrand.h"  //Implementation rematining ###########################################
#include "simFunctions.h"


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