#include <stdio.h>
#include <conio.h>
#define MAX 30

void main() {
    int i, j, n, t;
    int p[MAX], bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;

    system("cls");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst time
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                // Swap process numbers accordingly
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Calculate average
    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    awt = awt / n;
    atat = atat / n;

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    getch();
}

