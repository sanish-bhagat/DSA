#include <bits/stdc++.h>
using namespace std;

int solve(int line, int station, int a[][4], int t[][4], int e[])
{
    // base case -> return the exit_time for the curr line and processing time for the current station
    if (station == 0)
        return e[line] + a[line][0];

    // come from same line -> include the curr station cost
    int same_line = solve(line, station - 1, a, t, e) + a[line][station];

    // switch line -> include the swicthing cost + procesing cost for curr station
    int switch_line = solve(1 - line, station - 1, a, t, e) + t[1 - line][station] + a[line][station];

    // return the minimum of both the cost
    return min(same_line, switch_line);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int carAssembly(int a[][4], int t[][4], int e[], int x[], int n)
{
    // time cost for line 1
    int t1 = solve(0, n - 1, a, t, e) + x[0];

    // time cost for line 2
    int t2 = solve(1, n - 1, a, t, e) + x[1];

    // pick the minimum of both the time cost required
    return min(t1, t2);
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