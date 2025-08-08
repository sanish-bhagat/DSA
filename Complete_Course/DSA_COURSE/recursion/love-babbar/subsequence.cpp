#include <bits/stdc++.h>
using namespace std;

void solve(string &v, string output, int index, vector<string> &ans)
{

    // base case
    if (index >= v.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(v, output, index + 1, ans);

    // include
    char element = v[index];
    output.push_back(element);
    solve(v, output, index + 1, ans);
}

vector<string> subsequence(string &v)
{

    vector<string> ans;
    string output = "";

    int index = 0;

    solve(v, output, index, ans);
    return ans;
}

int main()
{
    string v = {"abc"};

    vector<string> ans = subsequence(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}