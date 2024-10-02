#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>  // Include GTK+ header
#include "process.h"
#include "scheduler.h"

// Global variables for the input fields
GtkWidget *process_id_entry;
GtkWidget *arrival_time_entry;
GtkWidget *burst_time_entry;
GtkWidget *priority_entry;

// Function to run when the "Run Scheduler" button is clicked
static void on_run_scheduler(GtkWidget *widget, gpointer data) {
    Scheduler scheduler;
    scheduler.processes = NULL;
    scheduler.count = 0;

    // Retrieve values from GTK input fields
    const gchar *process_id = gtk_entry_get_text(GTK_ENTRY(process_id_entry));
    const gchar *arrival_time = gtk_entry_get_text(GTK_ENTRY(arrival_time_entry));
    const gchar *burst_time = gtk_entry_get_text(GTK_ENTRY(burst_time_entry));
    const gchar *priority = gtk_entry_get_text(GTK_ENTRY(priority_entry));

    // Convert the input values to integers
    Process p;
    p.pid = atoi(process_id);
    p.arrival_time = atoi(arrival_time);
    p.burst_time = atoi(burst_time);
    p.priority = atoi(priority);

    add_process(&scheduler, p);  // Add process to the scheduler

    GanttChart gantt[100];  // Assuming a max of 100 process slots in the Gantt chart
    int gantt_count = 0;

    fcfs(&scheduler, gantt, &gantt_count);  // Call the FCFS scheduling function

    // Display results in a message dialog
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Process Scheduling Results", 
                                                    NULL, 
                                                    GTK_DIALOG_MODAL, 
                                                    "OK", GTK_RESPONSE_OK, 
                                                    NULL);
    gchar result_text[1024];
    gchar gantt_text[1024] = "Gantt Chart:\n";

    for (int i = 0; i < scheduler.count; i++) {
        Process* proc = &scheduler.processes[i];
        sprintf(result_text + strlen(result_text), 
                "Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n",
                proc->pid, proc->waiting_time, proc->turnaround_time);
    }

    for (int i = 0; i < gantt_count; i++) {
        sprintf(gantt_text + strlen(gantt_text), "| P%d ", gantt[i].process_id);
    }
    strcat(gantt_text, "|\n");

    for (int i = 0; i < gantt_count; i++) {
        sprintf(gantt_text + strlen(gantt_text), "%d ", gantt[i].start_time);
    }
    sprintf(gantt_text + strlen(gantt_text), "%d\n", gantt[gantt_count - 1].end_time);

    strcat(result_text, gantt_text);  // Combine results and Gantt chart
    gtk_label_set_text(GTK_LABEL(gtk_label_new(result_text)), result_text);  // Display results in the dialog

    // Free the allocated memory
    free(scheduler.processes);
    
    // Show the dialog
    gtk_widget_show_all(dialog);
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Process Scheduling Simulator");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a vertical box to hold input fields and buttons
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create input fields
    process_id_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), process_id_entry, TRUE, TRUE, 0);
    gtk_entry_set_placeholder_text(GTK_ENTRY(process_id_entry), "Process ID");

    arrival_time_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), arrival_time_entry, TRUE, TRUE, 0);
    gtk_entry_set_placeholder_text(GTK_ENTRY(arrival_time_entry), "Arrival Time");

    burst_time_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), burst_time_entry, TRUE, TRUE, 0);
    gtk_entry_set_placeholder_text(GTK_ENTRY(burst_time_entry), "Burst Time");

    priority_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), priority_entry, TRUE, TRUE, 0);
    gtk_entry_set_placeholder_text(GTK_ENTRY(priority_entry), "Priority");

    // Create Run button
    GtkWidget *run_button = gtk_button_new_with_label("Run Scheduler");
    g_signal_connect(run_button, "clicked", G_CALLBACK(on_run_scheduler), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), run_button, TRUE, TRUE, 0);

    // Connect the destroy signal to exit the application
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Enter the main event loop
    gtk_main();

    return 0;
}
