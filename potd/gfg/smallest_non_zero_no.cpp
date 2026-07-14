#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int find(vector<int> &arr)
{
    int need = 0;

    // Process the array from right to left
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // Minimum value required before processing arr[i]
        need = (need + arr[i] + 1) / 2;
    }

    return need;
}

int main()
{
    vector<int> arr = {3, 4, 3, 2, 4};

    cout << find(arr);

    return 0;
}