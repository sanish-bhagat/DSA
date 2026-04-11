#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countIncreasing(vector<int> &arr)
{
    int cnt = 0;

    // intialise the start index of the subarray
    int start = 0;

    // traverse through the arr[]
    for (int end = 1; end < arr.size(); end++)
    {
        // the element is valid for the curr subarray ->
        // increment the subarray count
        if (arr[end - 1] < arr[end])
            cnt += (end - start);

        // curr element is not valid for curr subarray -> start a new one
        else
            start = end;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 4, 5, 3, 7, 9};
    cout << countIncreasing(arr);
}