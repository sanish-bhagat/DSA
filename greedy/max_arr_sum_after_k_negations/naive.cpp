#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(1)

int maximizeSum(vector<int> &arr, int k)
{
    int n = arr.size();

    // perform k modifications
    for (int i = 0; i < k; i++)
    {
        int minIndex = 0;

        // find the minimum elements
        for (int j = 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // perform the modification
        arr[minIndex] = -arr[minIndex];
    }

    // find the sum of the modified arr[]
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    vector<int> arr = {-2, 0, 5, -1, 2};
    int k = 4;
    cout << maximizeSum(arr, k);
    return 0;
}