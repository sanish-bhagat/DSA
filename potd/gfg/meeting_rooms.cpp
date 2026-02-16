#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

bool canAttend(vector<vector<int>> &arr)
{
    // sort meetings based on the start time
    sort(arr.begin(), arr.end());

    // 1st meeting start and end timing
    int start1 = arr[0][0], end1 = arr[0][1];

    // traverse through the sorted meetings
    for (int i = 1; i < arr.size(); i++)
    {
        // curr meeting stzrt and end time
        int start2 = arr[i][0], end2 = arr[i][1];

        // meetings overlap -> curr meeting's start time < prev's end time
        if (start2 < end1)
            return false;

        // no overlap -> update variables
        else
            start1 = start2, end1 = end2;
    }

    // no meetings overlap
    return true;
}

int main()
{
    vector<vector<int>> arr = {{1, 4}, {10, 15}, {7, 10}};

    cout << canAttend(arr);
}