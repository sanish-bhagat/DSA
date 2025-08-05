#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

//! TC is O(n * logn)
//! SC is O(logn)

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // heapify the array
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    // sort the heapified array
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);

        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

    // Function call
    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
}