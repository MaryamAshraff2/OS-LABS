#include <stdio.h>
#include <conio.h>
#define MAX 30

void main() {
    int i, j, n;
    int bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;

    system("cls");

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    // Display process info
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate averages
    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    getch();
}

