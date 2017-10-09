# Single Server Queue Simulation 
**This is a project on creating a single server based queuing system**

### To Dos:
- [X] Implement main()
- [X] void initialize();
- [X] void timing();
- [X] void arrive();
- [X] void depart();
- [X] void report();
- [X] void update_stats();
- [X] float generator();
- [X] Implement arrive()
- [X] Implement depart()

## Definitions of the global variables used(shared across functions):
**State Variables:**		
- *int:*
  - num_custs_delayed: instant of time a customer is delayed
  - num_delays_required: How many customers to run simulation for?  => **input.txt line 3**
  - next_event_type: 1 is arrive() 2 is depart() 
  - num_events: 2 events possible so set at 2 used by timing()
  - num_in_queue: number of cust in a queue at an instant
  - server_status: state of server BUSY or IDLE
- *float:*
  - sim_time: time of simulation
  - time_last_event: time of last arrival or departure
  - time_next_event[2]: 
    - time_next_event[0] : represents the time next arrival will occur
    - time_next_event[1] : represents the time next departure will occur 

**Statistical counters:**
- *float:
  - avg_num_in_q: average number of cust in queue 
  - avg_server_util: average utilisation of server (0-1)
  - avg_interarrival: What is the average rate at which customers arrive. i.e. mean of Poisson process to be => **input.txt line 1**
  - avg_service_time: We assume that a service usually takes about a fixed time. i.e. Approximation how long service takes => **input.txt line 2**
  - time_arrival[Q_LIMIT+1]: The arrival time array of all customers in the queue at any instant
  - total_delays: Used to calculate average delay in report(). Holds cumilitive delay for all customers.

## Building and running
**After cloning into a local repo:**
  - compile as gcc main.c -lm
  - load 3 lines of input values into input.txt:
    - line 1: mean for arrival rate (used to generate arrival time in Poisson distribution )
    - line 2: mean for service rate (an estimation of how long each service take)
    - line 3: desired number of customers to run simulation for (imported as num_delays_required)
  - run binary program as ./a.out

Feel free to leave any comments. Peace! &#9996;