#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "scheduler.h"

void round_robin(Scheduler* scheduler, int time_quantum, GanttChart gantt[], int* gantt_count) {
    int time = 0;              // Current time
    int completed = 0;         // Number of completed processes
    int remain_burst_time[scheduler->count];  // Remaining burst times for each process

    // Initialize remaining burst time for each process
    for (int i = 0; i < scheduler->count; i++) {
        remain_burst_time[i] = scheduler->processes[i].burst_time;
    }

    while (completed < scheduler->count) {
        for (int i = 0; i < scheduler->count; i++) {
            if (remain_burst_time[i] > 0) {
                GanttChart entry;
                entry.process_id = scheduler->processes[i].pid;
                entry.start_time = time;

                // Check if the remaining burst time is greater than the time quantum
                if (remain_burst_time[i] > time_quantum) {
                    time += time_quantum;
                    remain_burst_time[i] -= time_quantum;
                } else {
                    // Process completes in this time slice
                    time += remain_burst_time[i];
                    remain_burst_time[i] = 0;
                    completed++;

                    // Calculate waiting time and turnaround time
                    scheduler->processes[i].waiting_time = time - scheduler->processes[i].arrival_time - scheduler->processes[i].burst_time;
                    scheduler->processes[i].turnaround_time = time - scheduler->processes[i].arrival_time;
                }

                entry.end_time = time;
                gantt[(*gantt_count)++] = entry;
            }
        }
    }
}

int main() {
    Scheduler scheduler;
    scheduler.processes = NULL;
    scheduler.count = 0;

    int n, time_quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Process p;
        printf("Enter Process ID, Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &p.priority);
        add_process(&scheduler, p);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    GanttChart gantt[100];  // Assuming a max of 100 process slots in the Gantt chart
    int gantt_count = 0;

    // Call Round Robin scheduling
    round_robin(&scheduler, time_quantum, gantt, &gantt_count);

    printf("Process Scheduling Results:\n");
    for (int i = 0; i < scheduler.count; i++) {
        Process* p = &scheduler.processes[i];
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n",
               p->pid, p->waiting_time, p->turnaround_time);
    }

    // Print the Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_count; i++) {
        printf("|  P%d  ", gantt[i].process_id);
    }
    printf("|\n");

    for (int i = 0; i < gantt_count; i++) {
        printf("%d      ", gantt[i].start_time);
    }
    printf("%d\n", gantt[gantt_count - 1].end_time);  // End time of the last process

    // Execution completed message
    printf("\n----------------------------//////Execution Completed\\\\\\\\--------------------------------\n");

    free(scheduler.processes);  // Free the allocated memory
    return 0;
}
