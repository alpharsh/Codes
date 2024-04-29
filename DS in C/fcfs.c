// WAP to implement FCFS CPU scheduling algorithm with arrival time

#include<stdio.h>

int main()
{
    int n, i, j;
    float avgtat=0;
    float avgwt=0;

    printf("Enter the no process: ");
    scanf("%d", &n);

    int tmp, bt[n], at[n], wt[n], tat[n];
    printf("Enter the Burst Time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the Arrival Time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    
    // Sort the process based on arrival time
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if(at[j]>at[j+1])
            {
                tmp=at[j];
                at[j]=at[j+1];
                at[j+1]=tmp;

                tmp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=tmp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0]=0;
    for (i=1; i<n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1]-(at[i]-at[i-1]);
        if(wt[i]<0)
        {
            wt[i]=0;
        }
    }

    for (i=0; i<n; i++)
    {
        tat[i]=bt[i]+wt[i];
    }

    // Calculate the average waiting time and average turnaround time
    for (i=0; i<n; i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    avgwt/=n;
    avgtat/=n;

    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1,at[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    return 0;
}