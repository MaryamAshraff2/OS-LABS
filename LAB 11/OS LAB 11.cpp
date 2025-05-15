#include <iostream>
using namespace std;

int main() {
    int b[20], l[20], n, i, pa, s, a, d;

    cout << "\nProgram for Segmentation";
    cout << "\nEnter the number of segments: ";
    cin >> n;

    cout << "\nEnter the base address and limit register for each segment:\n";
    for (i = 0; i < n; i++) {
        cout << "Segment " << i << " base: ";
        cin >> b[i];
        cout << "Segment " << i << " limit: ";
        cin >> l[i];
    }

    cout << "\nEnter the segment number: ";
    cin >> s;

    cout << "Enter the offset (logical address within segment): ";
    cin >> d;

    if (s < n) {
        if (d < l[s]) {
            pa = b[s] + d;
            a = b[s];
            cout << "\n\tSegment\tBaseAddr\tPhysicalAddr\n";
            cout << "\t" << s << "\t" << a << "\t\t" << pa << "\n";
        } else {
            cout << "\nOffset exceeds segment limit.\n";
        }
    } else {
        cout << "\nInvalid segment number.\n";
    }

    return 0;
}

