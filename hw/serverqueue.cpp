void init_model(void){
	num_custs_delayed = 0;
	event_schedule(sim_time + expon(mean_interarrival,
		STREAM_INTERARRIVAL),EVENT_ARRIVAL);
}