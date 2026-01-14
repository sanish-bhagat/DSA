#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

double separateSquares(vector<vector<int>> &squares)
{
    double low = 1e18, high = -1e18;

    // find the search space
    for (auto &s : squares)
    {
        low = min(low, (double)s[1]);
        high = max(high, (double)s[1] + s[2]);
    }

    // max 60 iterations is enough for 1e-5 precision
    for (int i = 0; i < 60; i++)
    {
        double mid = (low + high) / 2.0;
        double below = 0.0, above = 0.0;

        // for every square -> min Y coordinate such that area below = area above
        for (auto &s : squares)
        {
            double y = s[1], l = s[2];

            // entire square is above
            if (mid <= y)
                above += l * l;

            // entire square is below
            else if (mid >= y + l)
                below += l * l;

            // line cuts the square
            else
            {
                below += l * (mid - y);
                above += l * (y + l - mid);
            }
        }

        // line too low -> move up
        if (below < above)
            low = mid;

        // line too high or equal -> move down
        else
            high = mid;
    }

    // return the min Y coordinate such that area above == area below
    return low;
}

int main()
{
    vector<vector<int>> squares = {
        {0, 0, 1},
        {2, 2, 1}};

    cout << separateSquares(squares);
}