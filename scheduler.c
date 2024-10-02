// scheduler.c

#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

void add_process(Scheduler* scheduler, Process process) {
    scheduler->processes = realloc(scheduler->processes, sizeof(Process) * (scheduler->count + 1));
    scheduler->processes[scheduler->count] = process;
    scheduler->count++;
}

void fcfs(Scheduler* scheduler, GanttChart* gantt, int* gantt_count) {
    int current_time = 0;
    *gantt_count = 0;
    for (int i = 0; i < scheduler->count; i++) {
        Process* p = &scheduler->processes[i];

        if (current_time < p->arrival_time) {
            current_time = p->arrival_time;  // Wait until the process arrives
        }

        p->completion_time = current_time + p->burst_time;
        p->turnaround_time = p->completion_time - p->arrival_time;
        p->waiting_time = p->turnaround_time - p->burst_time;

        // Adding Gantt Chart info
        gantt[*gantt_count].process_id = p->pid;
        gantt[*gantt_count].start_time = current_time;
        gantt[*gantt_count].end_time = p->completion_time;
        (*gantt_count)++;

        current_time = p->completion_time;  // Update current time to the end of the current process
    }
}
