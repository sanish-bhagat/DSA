#include <iostream>
#include<vector>
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
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;

    // for 1-based indexing
    int left = 2 * i ;
    int right = 2 * i + 1;

    // for 0-based indexing
    // left = 2 * i + 1, right = 2 * i + 2

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

//! TC is O(m + n)
//! SC is O(m + n)
vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {
    //step1 - merge both arrays into one
    vector<int> ans;  
    for(auto i : a)
        ans.push_back(i);
    for(auto i : b)
        ans.push_back(i);

    //step2 - build heap using merged array
    int size = ans.size();
    for(int i = size / 2 ; i> 0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {-1, 10,5,6,2};
    vector<int> arr2 = {-1, 12,7,9};

    vector<int> ans = mergeHeaps(arr1, arr2);
    cout << "Printing the array now" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}