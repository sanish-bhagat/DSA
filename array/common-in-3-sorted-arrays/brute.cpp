#include <bits/stdc++.h>
using namespace std;

//! TC is O((n1 + n2 + n3) * log n1)
//! SC is O(n1)

vector<int> common(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n1 = a.size(), n2 = b.size(), n3 = c.size();

    map<int, int> mpp;

    for (auto i : a)
    {
        mpp[i] = 1;
    }

    for (auto i : b)
    {
        if (mpp.find(i) != mpp.end() && mpp[i] == 1)
        {
            mpp[i] = 2;
        }
    }

    for (auto i : c)
    {
        if (mpp.find(i) != mpp.end() && mpp[i] == 2)
        {
            mpp[i] = 3;
        }
    }

    vector<int> res;

    for (auto i : mpp)
    {
        if (i.second == 3)
        {
            res.push_back(i.first);
        }
    }

    return res;
}

int main()
{
    vector<int> A = {1, 5, 10, 20, 30};
    vector<int> B = {5, 13, 15, 20};
    vector<int> C = {5, 20};

    vector<int> ans = common(A, B, C);

    cout << "Common elements: ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}