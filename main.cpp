#include "simlib/src/simlib.h"

#include <iostream>

#define EVENT_ARRIVAL 1    //Event type for arrival event
#define EVENT_DEPARTURE 2  //Event type for departure
#define LIST_QUEUE 1       // list number for the queue of customers in line
#define LIST_SERVER 2			 //list number for the server. Contains either 0(idle) or 1(busy)
#define SAMPST_DELAYS 1     //sampst variable (is used as a measure of performance in a simulation)
#define STREAM_INTERARRIVAL 1      //random number stream for INTERARRIVAL of customers (generated acc to dist)
#define STREAM_SERVICE 2						// random number stream for service time for customers (generated acc to dist)


/*declare non simlib global variables*/

int num_custs_delayed, num_delays_required;
float mean_interarrival, mean_service;
FILE *infile, *outfile;

// declare non simlib functions:
void init_model();
void arrive();
void depart();
void report();


using namespace std;
int main(){
	init();
	
	return 0;
}