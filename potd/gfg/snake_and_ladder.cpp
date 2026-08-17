#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//! TC is O(n * n)
//! Sc is O(n * n)

int minThrows(int n, vector<int> &lad, vector<int> &sn)
{
    vector<int> moves(n * n + 1, -1);
    vector<bool> vis(n * n + 1, false);

    // Store all snakes and ladders.
    for (int i = 0; i < (int)lad.size(); i += 2)
    {
        moves[lad[i]] = lad[i + 1];
    }
    for (int i = 0; i < (int)sn.size(); i += 2)
    {
        moves[sn[i]] = sn[i + 1];
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;

    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        int pos = cur.first;
        int dist = cur.second;

        if (pos == n * n)
        {
            return dist;
        }

        // Try all possible dice outcomes.
        for (int nxt = pos + 1; nxt <= pos + 6 && nxt <= n * n; nxt++)
        {
            if (!vis[nxt])
            {
                vis[nxt] = true;

                int dest = (moves[nxt] == -1) ? nxt : moves[nxt];
                q.push({dest, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{

    int n = 6;

    vector<int> lad = {3, 22, 5, 8, 11, 35, 20, 32};

    vector<int> sn = {17, 4, 19, 7, 34, 1, 21, 9};

    cout << minThrows(n, lad, sn) << endl;

    return 0;
}