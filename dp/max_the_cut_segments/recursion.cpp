#include <bits/stdc++.h>
using namespace std;

int maxCutHelper(int n, int x, int y, int z)
{
    // base cases
    if (n == 0)
        return 0;

    // base case -> on dividing the rod, length becomes negative -> invlaid cut
    if (n < 0)
        return -1;

    // try all three segments cut
    int cut1 = maxCutHelper(n - x, x, y, z);
    int cut2 = maxCutHelper(n - y, x, y, z);
    int cut3 = maxCutHelper(n - z, x, y, z);

    // pick the max one among them
    int maxi = max(cut1, max(cut2, cut3));

    // if no valid cut is found return invalid cut else return the max cut
    return (maxi == -1) ? -1 : maxi + 1;
}

//! TC is O(3 ^ n)
//! SC is O(n)

int maximizeTheCuts(int n, int x, int y, int z)
{
    int res = maxCutHelper(n, x, y, z);

    return (res == -1) ? 0 : res;
}

int main()
{

    int n = 11;
    int x = 2, y = 3, z = 5;

    cout << maximizeTheCuts(n, x, y, z);

    return 0;
}