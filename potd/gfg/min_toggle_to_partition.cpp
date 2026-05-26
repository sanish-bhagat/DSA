#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int minToggle(vector<int> &arr)
{
    int n = arr.size();

    // keep track of 1's count seen so far
    int oneCnt = 0;

    // min toggles required
    int toggle = 0;

    // traverse through the arr[]
    for (int x : arr)
    {
        // curr element is 1
        if (x == 1)
            oneCnt++;

        else
            // Two choices:
            // 1. Toggle current 0 to 1 -> toggle + 1
            // 2. Toggle all previous 1s to 0 -> oneCount
            toggle = min(toggle + 1, oneCnt);
    }

    return toggle;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0};
    cout << minToggle(arr);
}