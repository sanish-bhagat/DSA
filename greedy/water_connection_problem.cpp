#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + p)
//! SC is O(n)

vector<vector<int>> findWaterDistribution(int n, int p, vector<int> &a, vector<int> &b, vector<int> &d)
{
    // vectors to track the tanks, tap and diameters
    vector<int> outgoing(n + 1, -1);
    vector<int> incoming(n + 1, -1);
    vector<int> diameter(n + 1, -1);

    // populating arr[] with input values
    for (int i = 0; i < p; i++)
    {
        outgoing[a[i]] = b[i];
        incoming[b[i]] = a[i];
        diameter[a[i]] = d[i];
    }

    vector<vector<int>> res;

    // traverse in DFS manner
    for (int i = 1; i <= n; i++)
    {
        // find houoses that have tank(having outgoing connections but no incoming connections)
        if (outgoing[i] != -1 && incoming[i] == -1)
        {
            // track curr house and min diameter
            int curr = i, minDi = INT_MAX;

            // traverse until nno incoming connection is found(tap)
            while (outgoing[curr] != -1)
            {
                // update the min diameter
                minDi = min(minDi, diameter[curr]);

                // move to next house
                curr = outgoing[curr];
            }

            // push the tank-tap and diameter in res[]
            res.push_back({i, curr, minDi});
        }
    }

    return res;
}

void print2dArray(vector<vector<int>> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j];
            if (j != arr[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != arr.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{

    int n = 9, p = 6;
    vector<int> a = {7, 5, 4, 2, 9, 3},
                b = {4, 9, 6, 8, 7, 1},
                d = {98, 72, 10, 22, 17, 66};

    vector<vector<int>> ans = findWaterDistribution(n, p, a, b, d);

    print2dArray(ans);

    return 0;
}