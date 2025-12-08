#include <bits/stdc++.h>
using namespace std;

int countWaysRec(int i, int n, vector<int> &points)
{ 
    // base case: total score is exactly == n, valid combination
    if (n == 0)
        return 1;

    // base case: invalid case
    if (n < 0 || i == 3)
        return 0;

    // for every point value, we have two choices =>

    // either take the point value
    int take = countWaysRec(i, n - points[i], points);

    // or don't take the point value
    int notake = countWaysRec(i + 1, n, points);

    // return the total valid combinations that can be formed
    return take + notake;
}

//! TC is O(2 ^ n)
//! SC is O(n)

int countWays(int n)
{
    // point values that we can score
    vector<int> points = {3, 5, 10};

    // recursively explore all the combinations and pick up the valid ones
    return countWaysRec(0, n, points);
}

int main()
{
    int n = 20;
    cout << countWays(n);
    return 0;
}