#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> singleNum(vector<int> &arr)
{
    unordered_map<int, int> freq;

    // store the frequency of every element
    for (int x : arr)
        freq[x]++;

    vector<int> ans;

    // iterate through map
    for (auto p : freq)
    {
        // element appears only once
        if (p.second == 1)
            ans.push_back(p.first);
    }

    if (ans[0] > ans[1])
        swap(ans[0], ans[1]);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNum(arr);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}