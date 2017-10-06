# Single Server Simulation using simlib 
**This is a project on creating a single server based queuing system**

### To Dos:
- [ ] Implement arrive()
- [ ] Implement depart()
- [X] Implement main()

## Definitions of the global variables used(shared across functions):
State Variables:		
- int:
  - num_custs_delayed: instant of time a customer is delayed
  - num_delays_required: service time
  - next_event_type: 1 is arrive() 2 is depart() 
  - num_events: 2 events possible so set at 2 used by timing()
  - num_in_queue: number of cust in a queue at an instant
  - server_status: state of server BUSY or IDLE

float avg_num_in_q, avg_server_util, avg_interarrival, avg_service_time, sim_time, time_arrival[Q_LIMIT+1], 
    time_last_event, time_next_event[3],total_delays;