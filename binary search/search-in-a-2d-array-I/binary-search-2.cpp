#include <bits/stdc++.h>
using namespace std;

// TC is O(log (n* m))

bool search(vector<vector<int>> v, int target)
{
    int n = v.size(), m = v[0].size();
    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (v[row][col] == target)
            return true;
        else if (v[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};

    int target = 23;

    cout << search(v, target);
}