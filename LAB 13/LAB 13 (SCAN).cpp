#include <stdio.h>
#include <conio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], sum = 0;

//    clrscr();
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;  // assuming starting track 0
    t[1] = h;

    printf("Enter the tracks:\n");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Bubble sort to sort the tracks array
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the index of the head position
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }

    int p = 0;
    // Move towards the start (0)
    while (t[j] != 0) {
        atr[p] = t[j];
        j--;
        p++;
    }
    atr[p] = t[j];  // add 0
    p++;

    // Move towards the end of the track list
    for (int x = k + 1; x < n + 2; x++, p++) {
        atr[p] = t[x];
    }

    // Calculate total head movements
    for (i = 0; i < n + 1; i++) {
        if (atr[i] > atr[i + 1])
            d[i] = atr[i] - atr[i + 1];
        else
            d[i] = atr[i + 1] - atr[i];
        sum += d[i];
    }

    printf("\nAverage header movements: %f\n", (float)sum / n);
    getch();
    return 0;
}

