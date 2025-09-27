#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxLoot(vector<int> &arr)
{
    int n = arr.size();

    if (n <= 0)
        return 0;

    if (n == 1)
        return arr[0];

    int res = 0;

    // set previous two values
    int sLast = 0, last = arr[0];

    // compute curr value use prev two values
    for (int i = 1; i < n; i++)
    {
        res = max(arr[i] + sLast, last);
        sLast = last;
        last = res;
    }

    return res;
}

int main()
{
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}