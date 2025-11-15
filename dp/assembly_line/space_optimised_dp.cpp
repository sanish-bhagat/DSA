#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int carAssembly(int a[][4], int t[][4], int e[], int x[], int n)
{
    // time cost for line 1 -> entry time + processing time for station 0
    int first = e[0] + a[0][0];

    // time cost for line 2 -> entry time + processing time for station 0
    int second = e[1] + a[1][0];

    // process all the stations
    for (int i = 1; i < n; i++)
    {
        // either stay on the same line or switch the line
        int up = min(first + a[0][i], second + t[1][i] + a[0][i]);
        int down = min(second + a[1][i], first + t[0][i] + a[1][i]);

        // move forward
        first = up;
        second = down;
    }

    // pick the min one(including the exit time)
    return min(first + x[0], second + x[1]);
}

int main()
{
    int n = 4;
    int a[][4] = {{4, 5, 3, 2},
                  {2, 10, 1, 4}};
    int t[][4] = {{0, 7, 4, 5},
                  {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << carAssembly(a, t, e, x, n);

    return 0;
}