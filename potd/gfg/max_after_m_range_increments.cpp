#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int findMax(int n, vector<int> &a, vector<int> &b, vector<int> &k)
{
    vector<int> arr(n + 1, 0);

    // Start performing 'm' operations
    for (int i = 0; i < a.size(); i++)
    {
        // Store lower and upper index i.e. range
        int lowerbound = a[i];
        int upperbound = b[i];

        // Add k to the lower_bound
        arr[lowerbound] += k[i];

        // Reduce upper_bound+1 indexed value by k
        if (upperbound + 1 < arr.size())
            arr[upperbound + 1] -= k[i];
    }

    // Find maximum sum possible from all values
    int sum = 0, res = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        res = max(res, sum);
    }
    return res;
}

int main()
{
    int n = 5;
    vector<int> a = {0, 1, 2};
    vector<int> b = {1, 4, 3};
    vector<int> k = {100, 100, 100};
    cout << findMax(n, a, b, k);
    return 0;
}