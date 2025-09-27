#include <bits/stdc++.h>
using namespace std;

// TC is O(n * log m)

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int count(vector<vector<int>> v)
{
    int n = 5, m = 5;
    int cntMax = 0, ind = -1;

    for (int i = 0; i < n; i++)
    {
        int cntOnes = m - lowerBound(v[i], m, 1);

        if (cntOnes > cntMax)
        {
            cntMax = cntOnes;
            ind = i;
        }
    }
    return ind;
}

int main()
{
    vector<vector<int>> v = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}};

    cout << count(v);
}