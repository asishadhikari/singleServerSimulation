#ifndef MY_FUNC
#define MY_FUNC

/*initialises all statistical counters, simulation time(i.e sim_time), state variables (see readme), 
	time_next_event[2] (i.e. array of next arrival and departure time)*/ 
void initialize();

void timing();
void arrive();
void depart();
void report();
void update_stats();
float generator();

#endif