#include <stdio.h>
#include <conio.h>

int main() {
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;

//    clrscr();
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed:\n");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 1; i < n + 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = -tohm[i];
    }

    for (i = 1; i < n + 1; i++)
        tot += tohm[i];

    avhm = (float)tot / n;

    printf("Tracks traversed\tDifference between tracks\n");
    for (i = 1; i < n + 1; i++) {
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    }

    printf("\nAverage header movements: %f", avhm);
    getch();
    return 0;
}

