#include <bits/stdc++.h>
using namespace std;

//! TC is O(n!)
//! SC is O(n)

int tsp(vector<vector<int>> &cost)
{
    int n = cost.size();

    vector<int> nodes;

    // store all the nodes excluding the stating point(here 0)
    for (int i = 1; i < n; i++)
        nodes.push_back(i);

    // mincost ot travel all the nodes
    int minCost = INT_MAX;

    do
    {
        // curr permutation cost and starting node(which is fixed as 0)
        int currCost = 0;
        int currNode = 0;

        // explore all the nodes int this permutation and calculate the cost for it
        for (int i = 0; i < nodes.size(); i++)
        {
            // keep adding the cost required to travel from the curr node to the next node
            currCost += cost[currNode][nodes[i]];

            // move the currNode ptr to the next node
            currNode = nodes[i];
        }

        // add the cost required to return the starting point
        currCost += cost[currNode][0];

        // keep updating minCost
        minCost = min(minCost, currCost);
    } while (next_permutation(nodes.begin(), nodes.end())); // explore all permutations

    return minCost;
}

int main()
{

    vector<vector<int>> cost = {{0, 10, 15, 20},
                                {10, 0, 35, 25},
                                {15, 35, 0, 30},
                                {20, 25, 30, 0}};

    int res = tsp(cost);
    cout << res << endl;

    return 0;
}