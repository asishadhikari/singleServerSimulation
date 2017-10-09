/*Authored by Ashish Adhikari
        HU- 18
    Code inspired by program given in text book and most of the implementations are very similar 
    Areas marked with ?????????????? denote aspects which was unclear in the book and thus need to clarify
            with professor*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcgrand.h"

#define Q_LIMIT 100
#define BUSY 1  
#define IDLE 0

int next_event_type, num_custs_delayed, num_delays_required, num_events,
    num_in_q, server_status;
int busy = 2;

float area_num_in_q, area_server_status, mean_interarrival, mean_service,
     sim_time, time_arrival[Q_LIMIT+1], time_last_event, time_next_event[3],
     total_of_delays;

FILE *infile, *outfile;

void initialize();
void timing();
void arrive();
void depart();
void report();
void update_time_avg_stats();
float expon(float mean);

int main(){
    //contains mean_interarrival, mean_service, num_delays_required
    infile = fopen("input.in", "r");
    outfile = fopen("output.out", "w");
    num_events = 2; //arrive and depart events only

    //read input
    fscanf(infile, "%f %f %d", &mean_interarrival, &mean_service,
           &num_delays_required);
    
    fprintf(outfile, "\n\n\t\tThis file contains the log of the Simulation\n\n");
    fprintf(outfile,"Mean interarrival time%f minutes\n", mean_interarrival);
    fprintf(outfile, "The provided mean service rate is: %f per minute\n",mean_service);
    fprintf(outfile, "The provided number of delays required (number of times a customer enters empty line) is: %i\n",num_delays_required);
    initialize();
    //keep running simulation until the termination condition is  met. num_custs_delayed represents the 
        // number of customers who had to wait at the first place in the line (i.e. number of customers who were served)
    
    while(num_custs_delayed<num_delays_required){
        timing();  //updates next_event_type based on time_next_event[] and updates sim_time
        update_time_avg_stats();
        switch(next_event_type){
            case 0:
                fprintf(outfile, "List empty, program terminated at sim_time%f\n",sim_time);
                exit(EXIT_FAILURE);
            case 1:
                arrive();
            case 2:
                depart();
        }

        //print to file average delay in queue, average number in queue, server utilization, time _simulation ended
        report();
    //fclose(infile);
    //fclose(outfile);


    }
    return 0;
}


void initialize(){
    //initialise system clock
    sim_time = 0.0;
    //intialise state variables
    server_status = IDLE;
    num_in_q = 0;
    time_last_event = 0.0;
    //intialise statistical counters
    num_custs_delayed = 0;
    area_num_in_q = 0.0;
    area_server_status = 0;
    total_of_delays = 0.0;

    //initialise event list
    time_next_event[1]= sim_time + expon(mean_interarrival);
    time_next_event[2] = 1.0e+30;
}

void timing(){
    next_event_type = 0;
    float minimum_time= 1.0e+30;
    //find the next event type by determining the first event based on time_next_event[]
    for(int i = 1; i<=num_events;i++){
        if(time_next_event[i]<minimum_time){
            next_event_type = i;
            minimum_time = time_next_event[i];
            // ???????????????????????????????????????????????????/ WHAT WOULD HAPPEN IF arrival and departure have same time????
        }
    }
    //edge case: What if time_next_eventp[] is empty? ??????????????????????/ Don't really see how this could happen?????
    if(next_event_type==0){
        fprintf(outfile,"Program terminated due to empty list of events at simulation time %f\n",sim_time);
        exit(EXIT_FAILURE); 
    }
    //advance the simulation clock
    sim_time = minimum_time;
}

void arrive(){
    float delay;
    //if server is busy at a customer's arrival i.e there is a line 
    if(server_status==BUSY){
        num_in_q++;
        if(num_in_q>Q_LIMIT){
            fprintf(outfile, "Queue Limit reached at time %f\n",sim_time);
            exit(EXIT_FAILURE);
        }

        //note that the queue starts at 1 and last index is 100(as Q_LIMIT + 1 used in index see above^^) index 0 is unused
        time_arrival[num_in_q] = sim_time;
    }

    //if the server is idle at customer's arrival
    else{
        //delay for this customer is 0
        delay = 0;  
        //total delays for the customer (used to calculate average delay) 
        total_of_delays+=delay;
        //total number of customers who made it through the first place in the queue i.e. number of simulations
        num_custs_delayed+=1;
        //change server status to byst
        server_status=BUSY;
        //schedule the next departure event (note only one cust can depart)
        time_next_event[2] = sim_time + expon(mean_service);

    }
}

void depart(){
    float delay;   //holds the delay for a specific customer (as computed from time_arrival[Q_LIMIT+1] array)
    //if line empty
    if (num_in_q == 0){
        //make server idle
        server_status= IDLE;
        //remove departure from consideration
        time_next_event[2] = 1.0e+30;
    }
    //if queue not empty
    else{
        //decrease the number of custs in queue
        num_in_q--;
        //calculate delay for the departing customer (time_arrival[] is constantly being updated)
        delay = sim_time - time_arrival[1];
        //update the statistical counter for total delay to calculate average delay
        total_of_delays+=delay;
        //this customer was delayed (used to keep track of number of simulations)
        num_custs_delayed++;
        //schedule a departure time for this customer
        time_next_event[2] = sim_time + expon(mean_service);
        
        //move each customer one place in the queue
        for(int i = 1; i<=num_in_q; i++){
            time_arrival[i] = time_arrival[i+1];
       }     
    }    
}

void update_time_avg_stats(){
    //updates time average statistical counters
    /*statistical counters are:
        - area_num_in_q, - area_server_status, time_last_event
    */

    //compute time since last event (used to calc average) and update the last event time
    float time_since_last_event = sim_time - time_last_event;  //is first initialsed to 0.0 
    time_last_event = sim_time;

    //update server utilisation (0 - 1)
    area_server_status += server_status*time_since_last_event;

    //update average number of customers in line using time-length average function (summation_of(lenth(i)*delta.time(i))/total_time) 
    area_num_in_q += area_num_in_q * time_since_last_event;
}



        //print to file average delay in queue, average number in queue, server utilization, time _simulation ended
void report(){
    fprintf(outfile, "\n\nThe average delay in the queue was %f\n",total_of_delays/num_custs_delayed);
    fprintf(outfile, "The average number of customer in the queue was %f\n",area_num_in_q/sim_time);
    fprintf(outfile, "The server utilization in this simulation was %f\n",area_server_status/sim_time);
    fprintf(outfile, "The simulation ended at time: %f\n\n\n",sim_time);

}

//exponential variate generation function for a given mean_service distribution mapped for mean
float expon(float mean){
    return (-mean*log(lcgrand(mean_service)));
}

