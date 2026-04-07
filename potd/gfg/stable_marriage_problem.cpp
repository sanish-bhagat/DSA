#include <bits/stdc++.h>
using namespace std;

// Check if woman prefers m over current partner m1
bool prefers(vector<vector<int>> &women, int w, int m, int m1)
{
    for (int i = 0; i < women[w].size(); i++)
    {
        if (women[w][i] == m)
            return true;

        if (women[w][i] == m1)
            return false;
    }

    return false;
}

//! TC is O(n * n)
//! SC is O(n)

vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
{
    int n = men.size();

    // men's current partners
    vector<int> mPartner(n, -1);

    // women's current partners
    vector<int> wPartner(n, -1);

    // next proposal index
    vector<int> next(n, 0);

    // free men
    vector<bool> freeMan(n, true);

    int freeCount = n;

    while (freeCount > 0)
    {
        int m;

        for (m = 0; m < n; m++)
            if (freeMan[m])
                break;

        int w = men[m][next[m]];
        next[m]++;

        // If w is free
        if (wPartner[w] == -1)
        {
            wPartner[w] = m;
            mPartner[m] = w;
            freeMan[m] = false;
            freeCount--;
        }

        else
        {
            int m1 = wPartner[w];

            // If w prefers m over current partner
            if (prefers(women, w, m, m1))
            {
                wPartner[w] = m;
                mPartner[m] = w;

                freeMan[m] = false;
                freeMan[m1] = true;
            }
        }
    }

    return mPartner;
}

int main()
{
    int n = 3;

    vector<vector<int>> men = {
        {1, 0, 2},
        {2, 1, 0},
        {0, 2, 1}};

    vector<vector<int>> women = {
        {1, 0, 2},
        {2, 1, 0},
        {0, 2, 1}};

    vector<int> result = stableMarriage(men, women);

    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
            cout << " ";
    }

    return 0;
}