#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_PROCESS 10
#define TIME_QUANTUM 2

struct Processes{
    int pid;
    int arrival_time;
    int const_burst_time;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
    int startT;
    int endT;
};

struct Processes items[MAX_PROCESS];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == MAX_PROCESS - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue( struct Processes s1) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_PROCESS;
    items[rear] = s1;
  }
}

// Removing an element
struct Processes deQueue() {
  struct Processes element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % MAX_PROCESS;
    }
    return (element);
  }
}

void round_robin(struct Processes processes[], int n){

    int remaining_processes = n;
    int current_time = 0;
    int i=0;

        for(int i=0; i<remaining_processes; i++){
           enQueue(processes[i]);
        }

      while (!isEmpty()) {
        if (processes[i].burst_time > 0) {
          if (processes[i].burst_time <= TIME_QUANTUM) {
            current_time += processes[i].burst_time;
            int num = processes[i].burst_time;
            processes[i].burst_time = 0;
            processes[i].remaining_time = processes[i].burst_time;
            printf(" %d: %d - %d |", processes[i].pid, (current_time - num), current_time);
            processes[i].startT = (current_time-num);
            processes[i].waiting_time += processes[i].startT-processes[i].endT;
            processes[i].endT = current_time;
            deQueue();
            remaining_processes--;
          } else {
            current_time += TIME_QUANTUM;
            processes[i].burst_time -= TIME_QUANTUM;
            processes[i].remaining_time = processes[i].burst_time;
            enQueue(deQueue());
            processes[i].startT = (current_time-TIME_QUANTUM);
            processes[i].waiting_time += processes[i].startT -processes[i].endT;
            processes[i].endT = current_time;
            printf(" %d: %d - %d |", processes[i].pid, (current_time - TIME_QUANTUM), current_time);
               
        }
    }

    i = (i + 1) % n;
        
}     
}

int main(){

     struct Processes processes[] = {
        {101, 0, 5, 5, 5, 0, 0,0},
        {105, 2, 3, 3, 3, 0, 0,0},
        {120, 4, 1, 1, 1, 0, 0,0},
        {111, 6, 2, 2, 2, 0, 0,0},
    };

    int n = sizeof(processes)/sizeof(processes[0]);

    round_robin(processes,n);
      printf("\n................................................................\n");
      printf("ProcessID\tBurst_Times\t Waiting_Time\tTurnaround_Time\n");
      printf("................................................................\n");
      for(int i=0; i<n; i++){
          processes[i].turnaround_time = processes[i].const_burst_time+processes[i].waiting_time-processes[i].arrival_time;
          printf(" %d \t\t%d\t\t\t%d\t\t%d\n", processes[i].pid,processes[i].const_burst_time,
                    processes[i].waiting_time,processes[i].turnaround_time);
      }
    
    return 0;
}