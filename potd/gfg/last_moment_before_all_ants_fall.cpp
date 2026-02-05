#include <bits/stdc++.h>
using namespace std;

//! TC is O(m)
//! SC is O(1)

int getLastMoment(int n, vector<int> &left, vector<int> &right)
{
    int res = 0;

    // time required to fall by ants moving towards left
    // ant will fall at 0
    for (int x : left)
        res = max(res, x);

    // time required to fall by ants moving towards right
    // moving towards right -> anst will fall at n, thats why n - right[i]
    for (int y : right)
        res = max(res, n - y);

    return res;
}

int main()
{
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0, 1, 3};
    cout << getLastMoment(n, left, right);
}