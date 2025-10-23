#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minDiceThrows(int N, vector<int> &arr)
{
    // target cell
    int target = 30;

    vector<int> moves(target + 1, -1);

    // build the moves for snake and ladders
    for (int i = 0; i < 2 * N; i += 2)
        moves[arr[i]] = arr[i + 1];

    // vis[] and queue for bfs(cell, dist)
    vector<bool> vis(target + 1, false);
    queue<pair<int, int>> q;

    // start from the 1st cell
    vis[1] = true;
    q.push({1, 0});

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        // curr cell and dist
        int cell = f.first, dist = f.second;

        // reached the target cell
        if (cell == target)
            return dist;

        // explore all the 1-6 values of dices
        for (int dice = 1; dice <= 6; dice++)
        {
            // next cell with the selected dice value
            int next = cell + dice;

            // next cell is in-bound and not visited yet -> visit the node
            if (next <= target && !vis[next])
                vis[next] = true;

            // ladder or snake is present in the curr cell
            if (moves[next] != -1)
                next = moves[next];

            // push the next cell and incremented dist
            q.push({next, dist + 1});
        }
    }

    return -1;
}

int main()
{
    int N = 8;
    vector<int> arr = {
        3, 22,  // ladder from 3 → 22
        5, 8,   // ladder from 5 → 8
        11, 26, // ladder from 11 → 26
        20, 29, // ladder from 20 → 29
        17, 4,  // snake from 17 → 4
        19, 7,  // snake from 19 → 7
        21, 9,  // snake from 21 → 9
        27, 1   // snake from 27 → 1
    };

    cout << "Minimum dice throws required: " << minDiceThrows(N, arr) << endl;
    return 0;
}