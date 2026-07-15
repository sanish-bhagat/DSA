#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int bitonic(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int maxLen = 1;

    int start = 0, nextStart = 0, j = 0;

    while (j < n - 1)
    {
        // look for the end of the ascent
        while (j < n - 1 && arr[j] <= arr[j + 1])
            j++;

        // look for the end of the descent
        while (j < n - 1 && arr[j] >= arr[j + 1])
        {
            // adjusting nextStart; this will be executed
            // when we detect the start of the descent
            if (j < n - 1 && arr[j] > arr[j + 1])
                nextStart = j + 1;

            j++;
        }

        maxLen = max(maxLen, j - start + 1);

        start = nextStart;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {12, 4, 78, 90, 45, 23};
    cout << bitonic(arr) << endl;
    return 0;
}