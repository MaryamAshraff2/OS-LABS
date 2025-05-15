#include <stdio.h>

int main() {
    int p[28], bt[28], pri[28], wt[28], tat[28], i, j, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    for (i = 0; i < n; i++) {
        p[i] = i + 1;  // Process number
        printf("Enter the Burst Time and Priority of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sort by priority (lower number = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pri[i] > pri[j]) {
                // Swap priority
                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
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

    // Calculate averages
    for (i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}

