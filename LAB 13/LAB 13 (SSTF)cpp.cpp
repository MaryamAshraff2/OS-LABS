#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    // Logic for SSTF disk scheduling
    while (count != n) {
        int min = 1000, d, index = -1;

        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (min > d) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = 1000;  // Mark as visited (large number)
        count++;
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}

