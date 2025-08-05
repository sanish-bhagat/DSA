#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int index, vector<string> &ans)
{

    // base case
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        solve(str, index + 1, ans);

        // backtrack => wapis original string pass krrna h issliye
        swap(str[index], str[j]);
    }
}

vector<string> permutataion(string &str)
{
    vector<string> ans;

    int index = 0;

    solve(str, index, ans);

    return ans;
}

int main()
{
    string str = {"abc"};

    vector<string> ans = permutataion(str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}