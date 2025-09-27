#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool findPair(vector<int> &arr, int x)
{

    int n = arr.size();
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.count(arr[i] + x) || st.count(arr[i] - x))
            return true;

        st.insert(arr[i]);
    }

    return false;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findPair(v, 0);
}