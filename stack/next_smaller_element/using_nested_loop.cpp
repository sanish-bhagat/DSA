#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

vector<int> findNextSmallerElement(vector<int> &arr)
{
    vector<int> res;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int next = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                next = arr[j];
                break;
            }
        }

        res.push_back(next);
    }

    return res;
}

int main()
{
    // Input array
    vector<int> arr = {4, 8, 2, 1, 6, 10, 5};

    // Function call to find next smaller elements
    vector<int> result = findNextSmallerElement(arr);

    // Print the original array
    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Print the next smaller elements
    cout << "Next Smaller Elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}