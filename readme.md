# Single Server Simulation using simlib 
**This is a project on creating a single server based queuing system**

### To Dos:
- [ ] Implement arrive()
- [ ] Implement depart()
- [X] Implement main()

## Definitions of the global variables used:
		
int num_custs_delayed, num_delays_required, next_event_type, num_events, num_in_queue, server_status; //state variables
float avg_num_in_q, avg_server_util, avg_interarrival, avg_service_time, sim_time, time_arrival[Q_LIMIT+1], 
    time_last_event, time_next_event[3],total_delays;