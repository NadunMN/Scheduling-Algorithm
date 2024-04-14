Round Robin-
       This C program simulates the Round Robin scheduling algorithm, a preemptive CPU scheduling algorithm where each process is assigned a fixed time quantum for execution. Processes are enqueued initially and executed in a cyclic manner until their burst time becomes zero. If the remaining burst time of a process is less than or equal to the time quantum, it completes its execution; otherwise, it executes for the time quantum and enqueues again. The program calculates waiting time, turnaround time, and completion time for each process and displays the results.

FIFO-
	This C program simulates CPU scheduling using the First-Come, First-Served (FCFS) algorithm. It prompts the user to input the number of processes, arrival time, and burst time for each process. Then, it calculates and displays the waiting time and turnaround time for each process. Finally, it deallocates the memory used by the processes.

SJF-
	This C program simulates CPU scheduling using the Shortest Job First (SJF) algorithm. It prompts the user to input the number of processes, arrival time, and burst time for each process. Then, it sorts the processes based on their burst time in ascending order. After sorting, it calculates and displays the waiting time and turnaround time for each process. Finally, it deallocates the memory used by the processes.
