#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    //! TC is O(log n)
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            // check krro ki parent apne child se bara ho, if not then swap krrdo child aur parent wala element ko
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    //! TC is O(log n)
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step1 - put last element into first index
        arr[1] = arr[size];

        // step2 - remove last element
        size--;

        // step3 - take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

//! TC is O(log n)
void heapify(int arr[], int n, int i)
{
    int largest = i;

    //for 1-based indexing
    int left = 2 * i;
    int right = 2 * i + 1;

    //for 0-based indexing
    //left = 2 * i + 1, right = 2 * i + 2

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//! TC is O(n log n) =>
// you will be given an array
// first build heap O(n)
//then heap sort O(log n)

void heapSort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        //step1 - swap
        swap(arr[size], arr[1]);
        size--;

        //step2 
        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(55);
    h.insert(50);
    h.insert(53);
    h.insert(54);
    h.insert(52);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing the sorted array now" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}