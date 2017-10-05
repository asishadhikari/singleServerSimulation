#include <iostream>
#include <simlib.h>

#define EVENT_ARRIVAL 1 			//arrival event type
#define EVENT_DEPARTURE 2			//departure event type
#define LIST_QUEUE 1					//list number (attribute number) for queue
#define LIST_SERVER 2					// list number for the server
#define SAMPST_DELAYS 1 			//sampst variable for delay in queue  sampst(value, variable) use delay time as sampst variable to analyse wait time
#define STREAM_INTERARRIVAL 1  //random number stream for interarrival times
#define STREAM_SERVICE 2        //random number stream for service times

int num_custs_delayed, num_delays_required;
float mean_interarrival, mean_service;
FILE* fp;

int main(){
	init_simlab();
	//timest and sampst mainain 20 internal "registers" for analysis
	sampst(0.0,0); //reset all sampst variables
	timest(0.0,0); //reset all timest variables
	
	return 0;
}