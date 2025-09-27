#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int getMaxArea(vector<int> &arr)
{
    int res = 0, n = arr.size();

    //traverse the array
    for (int i = 0; i < n; i++)
    {
        //pick the curr element as the min height of the rect
        int curr = arr[i];

        //traverse the left side of the curr element
        for (int j = i - 1; j >= 0 && arr[j] >= arr[i]; j--)
            curr += arr[i];

        //traverse the right side
        for (int j = i + 1; j < n && arr[j] >= arr[i]; j++)
            curr += arr[i];

        //update the res
        res = max(res, curr);
    }

    return res;
}

int main()
{
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}