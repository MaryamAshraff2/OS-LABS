#include <iostream>
using namespace std;

int main() {
    int ms, ps, nop, np, rempages;
    int s[10], fno[10][20];
    int i, j, x, y, pa, offset;

    // Input total memory size
    cout << "\nEnter the memory size -- ";
    cin >> ms;

    // Input page size
    cout << "\nEnter the page size -- ";
    cin >> ps;

    nop = ms / ps;  // Number of pages in memory
    cout << "\nThe number of pages available in memory are -- " << nop;

    // Input number of processes
    cout << "\nEnter number of processes -- ";
    cin >> np;

    rempages = nop;

    // Input for each process
    for (i = 1; i <= np; i++) {
        cout << "\nEnter number of pages required for p[" << i << "] -- ";
        cin >> s[i];

        if (s[i] > rempages) {
            cout << "\nMemory is Full";
            break;
        }

        rempages -= s[i];
        cout << "\nEnter page table for p[" << i << "] ---\n";

        for (j = 0; j < s[i]; j++) {
            cout << "Page " << j << " ? Frame: ";
            cin >> fno[i][j];
        }
    }

    // Logical to Physical Address translation
    cout << "\nEnter Logical Address to find Physical Address";
    cout << "\nEnter process no., page number and offset -- ";
    cin >> x >> y >> offset;

    if (x > np || y >= s[x] || offset >= ps) {
        cout << "\nInvalid Process or Page Number or Offset";
    } else {
        pa = fno[x][y] * ps + offset;
        cout << "\nThe Physical Address is -- " << pa;
    }

    return 0;
}

