#include <bits/stdc++.h>
using namespace std;

// Function to update the array in most recently used fashion
void recently(int* arr, int size, int elem)
{
    int index = 0;
    index = (elem % size);
    int temp = index, id = arr[index];

    while (temp > 0)
    {
        arr[temp] = arr[--temp];
    }
    arr[0] = id;
}

// Print array elements
void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() 
{
    int elem = 3;
    int arr[] = { 6, 1, 9, 5, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    recently(arr, size, elem);

    cout << "array in most recently used fashion : ";
    print(arr, size);

    return 0;
}

