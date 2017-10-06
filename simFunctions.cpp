#include "simFunctions.h"
#define Q_LIMIT 200  //maximum customers in allowed in queue
#define BUSY 1						//server busy
#define IDLE 0						//server idle


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
void timing(){}
void arrive(){}
void depart(){}
void report(){}
void update_stats(){}
float generator(){}