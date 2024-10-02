// process.h

#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int pid;           // Process ID
    int arrival_time;  // Arrival Time
    int burst_time;    // Burst Time
    int priority;      // Priority
    int waiting_time;  // Waiting Time
    int turnaround_time;// Turnaround Time
    int completion_time;// Completion Time
} Process;

#endif // PROCESS_H
