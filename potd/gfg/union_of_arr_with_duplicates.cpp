#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! SC is O(n + m)

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    // use set to store the distinct elements
    unordered_set<int> st(a.begin(), a.end());

    // store distinct elements(including elements of a and b both)
    // present in b
    for (int x : b)
        st.insert(x);

    // build the res[]
    vector<int> res;
    for (auto it = st.begin(); it != st.end(); it++)
        res.push_back(*it);

    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 1}, b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);

    sort(res.begin(), res.end());

    for (int x : res)
        cout << x << " ";
}