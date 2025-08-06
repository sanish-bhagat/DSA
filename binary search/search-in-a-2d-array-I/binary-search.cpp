#include <bits/stdc++.h>
using namespace std;

// TC is O(n) + O(log m)


//binary-search will be performed only once
bool binarySearch(vector<int> v, int m, int target)
{
    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

bool search(vector<vector<int>> v, int target)
{
    int n = 3, m = 4;
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] <= target && target <= v[i][m - 1])
        {
            return binarySearch(v[i], m, target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};

    int target = 18;

    cout << search(v, target);
}