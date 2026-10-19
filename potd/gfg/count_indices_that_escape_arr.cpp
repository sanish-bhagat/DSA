#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool dfs(int idx, vector<int> &arr, vector<int> &state)
{
    // out of index
    if (idx < 0 || idx >= arr.size())
        return true;

    // zero jump is a dead end
    if (arr[idx] == 0)
        return false;

    // already known as good index
    if (state[idx] == 2)
        return true;

    // cycle dectected
    if (state[idx] == 1)
        return false;

    // already known as bad index
    if (state[idx] == 3)
        return false;

    // mark curr index as visiting
    state[idx] = 1;

    // jump to the next index
    int newIdx = idx + arr[idx];

    bool good = dfs(newIdx, arr, state);

    // update the curr index state for future traversals
    state[idx] = good ? 2 : 3;

    return good;
}

int goodIndices(vector<int> &arr)
{
    int n = arr.size();

    // 0 = unvisited, 1 = visiting, 2 = good, 3 = bad
    vector<int> state(n, 0);

    int ans = 0;

    // check every index using dfs
    for (int i = 0; i < n; i++)
    {
        if (dfs(i, arr, state))
            ans++;
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, -1, 2, -2, 4, 1};
    cout << goodIndices(arr) << endl;

    return 0;
}