// You are given a list of daily transactions of a user:

// Positive → money credited
// Negative → money debited

// 👉 The bank wants to answer queries like:

// “What is the total balance change from day L to day R?”

#include <bits/stdc++.h>
using namespace std;

void solve(int start, int end, vector<int> &transactions, vector<int> &res)
{
    int sum = 0;

    // keep track of the running sum of this range
    for (int i = start; i <= end; i++)
        sum += transactions[i];

    // store the res of this query
    res.push_back(sum);
}

vector<int> totalBalanceChange(vector<int> &transactions, vector<pair<int, int>> &queries)
{
    // store the res for every queries
    vector<int> res;

    // compute the res
    for (auto it : queries)
        solve(it.first, it.second, transactions, res);

    return res;
}

int main()
{
    vector<int> transactions = {100, -50, 200, -100, 50};
    vector<pair<int, int>> queries = {{1, 3}, {0, 4}};

    vector<int> res = totalBalanceChange(transactions, queries);

    for (int x : res)
        cout << x << " ";
}