// scheduler.h

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"
// 
typedef struct {
    Process* processes; // Array of processes
    int count;          // Number of processes
} Scheduler;

// Struct for Gantt Chart
typedef struct {
    int process_id;
    int start_time;
    int end_time;
} GanttChart;

void add_process(Scheduler* scheduler, Process process);
void fcfs(Scheduler* scheduler, GanttChart* gantt, int* gantt_count);

#endif // SCHEDULER_H
