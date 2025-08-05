#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, vector<int> output, int index, vector<vector<int>> &ans)
{

    // base case
    if (index >= v.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(v, output, index + 1, ans);

    // include
    int element = v[index];
    output.push_back(element);
    solve(v, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &v)
{
    vector<vector<int>> ans;

    vector<int> output;

    int index = 0;

    solve(v, output, index, ans);

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3};

    vector<vector<int>> ans = subsets(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}