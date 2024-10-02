// main.c
#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "scheduler.h"



int main() {
    Scheduler scheduler;
    scheduler.processes = NULL;
    scheduler.count = 0;

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Process p;
        printf("Enter Process ID, Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &p.priority);
        add_process(&scheduler, p);
    }



    GanttChart gantt[100];  // Assuming a max of 100000 process slots in the Gantt chart
    int gantt_count = 0;

    fcfs(&scheduler, gantt, &gantt_count);

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

        //final execution end message
    printf("\n----------------------------//////Execution Completed\\\\\\--------------------------------\n");

    free(scheduler.processes);  // Free the allocated memory
    return 0;
}
