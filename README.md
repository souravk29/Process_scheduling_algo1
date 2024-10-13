# Process_scheduling_algo1
(kindly open README.md file in Code mode)
The Process Scheduler Simulator is a C-based application designed to simulate various CPU scheduling algorithms. This simulator helps users visualize how different scheduling algorithms manage processes in a system by generating a Gantt chart that displays the timeline of process execution. It provides a practical way to compare the efficiency and behavior of different algorithms such as FCFS (First-Come, First-Served), SJF (Shortest Job First), Priority Scheduling, and Round Robin.

Features: 
--> Multiple Scheduling Algorithms: Supports FCFS, SJF, Priority Scheduling, and Round Robin.
--> Gantt Chart Visualization: Generates a visual representation of process execution for each algorithm.
--> Detailed Statistics: Displays metrics such as Turnaround Time, Waiting Time, and Throughput.
--> Interactive User Input: Allows users to input process data like burst time, arrival time, and priorities.

======------------Scheduling Algorithms Implemented---------------======
First-Come, First-Served (FCFS): Processes are executed in the order they arrive.
Shortest Job First (SJF): Executes the process with the shortest burst time first.
Priority Scheduling: Executes processes based on priority, with higher priority processes being scheduled first.
Round Robin (RR): Each process is given a fixed time slice (quantum), and processes are cycled through in a queue.


////////////////////  Steps to Install  \\\\\\\\\\\\\\\\\\\\\\\
Clone the Repository:
Bash code -->  git clone https://github.com/PraTeekK123/Process_scheduling_algo1.git

Navigate to the Project Directory:
Bash code -->  cd Process_scheduling_algo1

Compile the Code:
Bash code -->  gcc process_scheduler.c -o scheduler

Run the Simulator:
Bash code -->  ./scheduler


--------------------Project Structure--------------------
├── process_scheduler.c  # Main source code for the scheduler
├── Makefile             # File for automating the build process
├── README.md            # Project documentation


Note: Features like Round Robin, Shortest Job First (SJF), Priority Scheduling are yet to implemented in code. 
