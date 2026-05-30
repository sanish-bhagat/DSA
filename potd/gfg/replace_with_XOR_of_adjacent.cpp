#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

void replaceElements(vector<int> &arr)
{
    int n = arr.size();

    // keep track of previous element
    int prev = arr[0];

    for (int i = 0; i < n; i++)
    {
        // for first index
        if (i == 0)
            arr[i] = arr[i] ^ arr[i + 1];

        // for last index
        else if (i == n - 1)
            arr[i] = arr[i] ^ prev;

        // update the prev value for next iteration and
        // curr index value by the XOR of adjacents
        else
        {
            int temp = prev ^ arr[i + 1];
            prev = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    vector<int> arr = {5, 9, 2, 6, 7};
    replaceElements(arr);

    for (int x : arr)
        cout << x << " ";
}