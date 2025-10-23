#include <bits/stdc++.h>
using namespace std;

void dfs(int cell, vector<int> &moves, vector<int> &vis, int throws, int &minThrows)
{
    // reached the target cell -> find the minThrows and return
    if (cell == 30)
    {
        minThrows = min(throws, minThrows);
        return;
    }

    // If already reached this cell in fewer or equal throws, prune this path
    if (vis[cell] <= throws)
        return;

    // throws required to reach this cell
    vis[cell] = throws;

    // explore for all the 1-6 values of the dice
    for (int dice = 1; dice <= 6; dice++)
    {
        int next = cell + dice;

        // out of bound
        if (next > 30)
            continue;

        // ladder or snake is present in the curr cell
        if (moves[next] != -1)
            next = moves[next];

        // dfs for the next cell with incremented throw
        dfs(next, moves, vis, throws + 1, minThrows);
    }
}

//! TC is O(n)
//! SC is O(n)

int minDiceThrows(int N, vector<int> &arr)
{
    vector<int> moves(31, -1);

    // build the moves for snake and ladders
    for (int i = 0; i < 2 * N; i += 2)
        moves[arr[i]] = arr[i + 1];

    // visited[i] = minimum number of throws used to reach i
    vector<int> vis(31, INT_MAX);
    int minThrows = INT_MAX;

    // recursive dfs to calculate the minthrows required
    dfs(1, moves, vis, 0, minThrows);

    return (minThrows != INT_MAX) ? minThrows : -1;
}

int main()
{
    int N = 8;
    vector<int> arr = {
        3, 22,  // ladder
        5, 8,   // ladder
        11, 26, // ladder
        20, 29, // ladder
        17, 4,  // snake
        19, 7,  // snake
        21, 9,  // snake
        27, 1   // snake
    };

    cout << "Minimum dice throws: " << minDiceThrows(N, arr) << endl;
    return 0;
}