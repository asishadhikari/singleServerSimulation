void initialize(){
	num_custs_delayed = 0;
	next_event_type = 1;
	num_events = 2;
	num_in_queue = 0;
	
	server_status = IDLE;
	sim_time = 0.0;
	time_last_event = 0.0;
	time_next_event[0] = sim_time + generator();
	time_next_event[1] = 100000000000000000000;


	avg_num_in_q = 0.0;
	avg_server_util = 0.0;
	time_arrival[Q_LIMIT + 1];
	total_delays = 0.0;

}
void timing();
void arrive();
void depart();
void report();
void update_stats();
float generator();