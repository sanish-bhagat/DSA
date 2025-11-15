#include <bits/stdc++.h>
using namespace std;

int solve(int line, int station, int a[][4], int t[][4], int e[], vector<vector<int>> &memo)
{
    // base case
    if (station == 0)
        return e[line] + a[line][0];

    // overlapping subproblem -> return the alerady computed result
    if (memo[line][station] != -1)
        return memo[line][station];

    // come from the same line
    int same_line = solve(line, station - 1, a, t, e, memo) + a[line][station];

    // swicth the line
    int switch_line = solve(1 - line, station - 1, a, t, e, memo) + t[1 - line][station] + a[line][station];

    // pick the min one
    return min(same_line, switch_line);
}

//! TC is O(2n)
//! SC is O(2n)

int carAssembly(int a[][4], int t[][4], int e[], int x[], int n)
{
    // using 2d[][] dp table for memoization of overlapping subproblems
    vector<vector<int>> memo(2, vector<int>(n, -1));

    // time cost for line 1
    int t1 = solve(0, n - 1, a, t, e, memo) + x[0];

    // time cost for line 2
    int t2 = solve(1, n - 1, a, t, e, memo) + x[1];

    // return the min cost
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