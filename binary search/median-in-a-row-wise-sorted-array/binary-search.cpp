#include <bits/stdc++.h>
using namespace std;

//! TC is O(log(maxElement)) * O(n * log m)

int upperBound(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int countSmallEqual(vector<vector<int>> v, int n, int m, int x)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += upperBound(v[i], x);
    }
    return cnt;
}

int median(vector<vector<int>> v)
{
    int low = INT_MAX, high = INT_MIN;
    int n = v.size();
    int m = v[0].size();

    for (int i = 0; i < n; i++)
    {
        low = min(low, v[i][0]);
        high = max(high, v[i][m - 1]);
    }

    int req = (n * m) / 2;

    // O(log(10^9))   maxElement => 10^9
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(v, n, m, mid);

        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<vector<int>> v = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}};

    cout << median(v);
}