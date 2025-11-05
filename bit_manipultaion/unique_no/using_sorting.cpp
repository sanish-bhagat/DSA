#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

vector<int> singleNum(vector<int> &arr)
{
    int n = arr.size();

    // sort arr to arrange the identical elements aside by aside
    sort(arr.begin(), arr.end());

    vector<int> ans;

    int i = 0;

    while (i < n)
    {
        // check if pairs of identical elements present, then skip them
        if (i + 1 < n && arr[i + 1] == arr[i])
            i = i + 2;

        // else, its a unique no.(appears only once)
        else
        {
            ans.push_back(arr[i]);
            i++;
        }
    }

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