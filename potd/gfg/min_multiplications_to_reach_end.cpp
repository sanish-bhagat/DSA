#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int minSteps(vector<int> &arr, int start, int end)
{
    int mod = 1000;

    // queue for bfs traversal
    queue<int> q;

    // queue for bfs traversal
    vector<int> dist(mod, -1);

    start = start % mod;
    end = end % mod;

    // start the bfs
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        // reached the end destination -> return the operations req to reach
        if (curr == end)
            return dist[curr];

        // traverse the arr[] and perform operations on the curr element
        for (int i = 0; i < arr.size(); i++)
        {
            // perform operation
            int next = (curr * arr[i]) % mod;

            // element not visited -> update req operations and push into queue
            if (dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    // not able to reach to end
    return -1;
}

int main()
{
    int start = 7;
    int end = 66175;
    vector<int> arr = {3, 4, 65};

    cout << minSteps(arr, start, end) << endl;

    return 0;
}