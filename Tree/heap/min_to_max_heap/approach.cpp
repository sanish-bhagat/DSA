#include<bits/stdc++.h>
using namespace std;

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[largest] < arr[l])
        largest = l;

    if(r < n && arr[largest] < arr[r])
        largest = r;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void convertMaxHeap(int arr[], int n) {
    // from the last non-leaf node -> 0,
        // call the maxHeapify to build a max heap
    for(int i=(n-1)/2; i>=0; i--)
        maxHeapify(arr, n, i);
}

int main()
{
    // array representing Min Heap
    int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Min Heap array : ");
    printArray(arr, N);

    // Function call
    convertMaxHeap(arr, N);

    printf("\nMax Heap array : ");
    printArray(arr, N);

    return 0;
}