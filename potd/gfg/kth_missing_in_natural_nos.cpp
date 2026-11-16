#include <bits/stdc++.h>
using namespace std;

//! TC is O(n logn)
//! SC is O(1)

int findKthSmall(vector<int> &arr, int k)
{
    // sort the arr[] in increasing order
    sort(arr.begin(), arr.end());

    int i = 0, num = 1, cnt = 0, n = arr.size();

    while (cnt < k)
    {
        // skip the no.s which are present in the arr[]
        if (i < n && arr[i] == num)
            i++;

        // remaining element
        else
        {
            cnt++;

            // k-th smallest missing element
            if (cnt == k)
                break;
        }

        num++;
    }

    return num;
}

int main()
{
    vector<int> arr = {1, 9, 5, 2};
    int k = 6;

    cout << findKthSmall(arr, k);
}