#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + k)
//! SC is O(1)

vector<int> update(int n, vector<int> &updates)
{
    vector<int> arr(n, 0);

    // cnt the no. of updates starting at every position
    for (int j : updates)
        arr[j - 1]++;

    // use prefix sum to build the final res[]
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += arr[i];

        arr[i] = cnt;
    }

    return arr;
}

int main()
{
    int n = 3;
    vector<int> updates = {1, 1, 2, 3};

    vector<int> result = update(n, updates);

    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            cout << ", ";
        cout << result[i];
    }
    cout << "]\n";

    return 0;
}