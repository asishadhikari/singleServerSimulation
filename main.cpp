#include <iostream>
#include <stdio.h>
#include <math.h>
#include "lcgrand.h"  //Implementation rematining ###########################################

#define Q_LIMIT 100  //maximum customers in allowed in queue
#define BUSY 1						//server busy
#define IDLE 0						//server idle


int num_custs_delayed, num_delays_required, next_event_type, num_events, num_in_queue, server_status; //state variables
float avg_num_in_q, avg_server_util, avg_interarrival, avg_service_time, sim_time, time_arrival[Q_LIMIT+1], 
    time_last_event, time_next_event[3],total_delays;

FILE *in, *out;
// declare non simlib functions:

void initialize();
void timing();
void arrive();
void depart();
void report();
void update_stats();
float generator();


using namespace std;
int main(){
	
	
	return 0;
}