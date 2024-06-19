// program to implement preemptive priority scheduling
#include <stdio.h>
#define MAX_PROCESSES 10

int main()
{
    int n; // Number of processes
    int burst_time[MAX_PROCESSES];
    int priority[MAX_PROCESSES];
    int wait_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    int remaining_time[MAX_PROCESSES];
    int arrival_time[MAX_PROCESSES];
    int complete = 0, current_time = 0, min_priority, shortest = 0;
    float total_wait = 0, total_turnaround = 0;
    int finish_time;
    int i;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time, arrival time and priority of each process
    printf("Enter burst time, arrival time and priority of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &burst_time[i]);
        printf("Arrival time: ");
        scanf("%d", &arrival_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        remaining_time[i] = burst_time[i];
    }

    // Set initial values
    if (n < 10)
    {
        remaining_time[9] = 10000; // Large number to ensure the loop starts correctly
    }
    // Process scheduling
    while (complete != n)
    {
        min_priority = 10000;
        // Find the process with the highest priority (lowest priority value) at the current time 
        for (i = 0; i < n; i++)
        {
            if (arrival_time[i] <= current_time && priority[i] < min_priority && remaining_time[i] > 0)
            {
                min_priority = priority[i];
                shortest = i;
            }
        }
        // Reduce remaining time of the process with the highest priority
        remaining_time[shortest]--;
        // Update the current time
        current_time++;
        // If a process is finished
        if (remaining_time[shortest] == 0)
        {
            complete++;
            finish_time = current_time;
            wait_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
            if (wait_time[shortest] < 0)
            {
                wait_time[shortest] = 0;
            }
            turnaround_time[shortest] = burst_time[shortest] + wait_time[shortest];
        }
    }
    // Calculate total waiting time and total turnaround time
    for (i = 0; i < n; i++)
    {
        total_wait += wait_time[i];
        total_turnaround += turnaround_time[i];
    }
    // Display results
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i], priority[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time = %.2f", total_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);
    return 0;
}