#include <stdio.h>
#include <stdlib.h>

#ifndef SJF_H
#define SJF_H

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time; 
    int executed; 
};

void sortProcesses(struct Process processes[], int n) {
    // Using bubble sort for simplicity
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void clacTime(struct Process processes[], int n){
    processes[0].waiting_time =0;

        for(int i=1; i<n; i++){
            processes[i].waiting_time = processes[i-1].waiting_time +processes[i-1].burst_time;
        }

        for(int i=0; i<n; i++){
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        }
}

void displayProcesses(struct Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main(){

     int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

  
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].executed = 0; 
    }

    sortProcesses(processes, n);
    clacTime(processes, n);
    displayProcesses(processes,  n);

    free(processes);
    return 0;
}

#endif