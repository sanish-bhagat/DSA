#include <bits/stdc++.h>
using namespace std;

//! Tc is O((n + m) ^ 2)
//! SC is O(1)

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> res;

    for (int i = 0; i < a.size(); i++)
    {
        int j;

        for (j = 0; j < res.size(); j++)
            if (res[j] == a[i])
                break;

        if (j == res.size())
            res.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        int j;

        for (j = 0; j < res.size(); j++)
            if (res[j] == b[i])
                break;

        if (j == res.size())
        {
            res.push_back(b[i]);
        }
    }

    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> ans = findUnion(a, b);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
