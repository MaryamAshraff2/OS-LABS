#include <stdio.h>

int main() {
    int i, j, n, t, time = 0;
    int bt[12], wt[12] = {0}, tat[12] = {0}, rt[12]; // Burst time, waiting time, turnaround time, remaining time
    float awt = 0, att = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Copy burst time to remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &t);

    // Round Robin Scheduling Logic
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > t) {
                    time += t;
                    rt[i] -= t;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i]; // waiting time = current time - burst time
                    rt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    // Calculate turnaround time and average times
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        att += tat[i];
        awt += wt[i];
    }

    printf("\nThe Average Turnaround Time is: %.2f", att / n);
    printf("\nThe Average Waiting Time is: %.2f", awt / n);

    printf("\n\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}

