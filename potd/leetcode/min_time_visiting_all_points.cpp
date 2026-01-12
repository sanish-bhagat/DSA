#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int time = 0;

    for (int i = 1; i < points.size(); i++)
    {
        // absolute difference between curr start and goal
        int dx = abs(points[i][0] - points[i - 1][0]);
        int dy = abs(points[i][1] - points[i - 1][1]);

        // diagonal moves = min(dx, dy)
        // remaining straight = max(dx, dy) - min(dx, dy)
        // total time = max(dx, dy) - (max(dx, dy) - min(dx, dy)) => max(dx, dy)
        time += max(dx, dy);
    }

    // return the min time required to reach all the points
    return time;
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    cout << minTimeToVisitAllPoints(points);
}