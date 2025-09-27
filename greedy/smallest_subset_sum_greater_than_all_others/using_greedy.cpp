#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * log n)
//! SC is O(1)

int minElements(vector<int> &arr)
{
    int n = arr.size();

    // total sum of the arr[]
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);

    // sort arr[] in descending order
    sort(arr.begin(), arr.end(), greater<int>());

    // variables for curr subset sum and no. of elements present
    int count = 0;
    long long currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        count++;

        // curr subset sum > the remaining sum, return the no. of elements in the curr subset
        if (currSum > totalSum - currSum)
            return count;
    }

    return count;
}

int main()
{
    vector<int> arr = {3, 1, 7, 1};
    cout << minElements(arr) << endl;
    return 0;
}