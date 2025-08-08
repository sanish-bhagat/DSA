#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

bool findPair(vector<int> arr, int x)
{

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (arr[j] - arr[i] == x)
                return true;
        }
    }

    return false;
}

int main()
{

    vector<int> v = {1, 8, 30, 40, 100};
    cout << findPair(v, -60);
}