#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int maxWater(vector<int> &arr)
{

    int n = arr.size();
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {

        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(arr[j], left);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        res += (min(left, right) - arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
    return 0;
}