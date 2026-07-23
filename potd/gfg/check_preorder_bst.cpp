#include <bits/stdc++.h>
using namespace std;

void solve(int &preIndex, int n, vector<int> &arr, int mini, int maxi)
{
    // base case
    if (preIndex >= n)
        return;

    // curr element can be a possible root
    if (mini <= arr[preIndex] && arr[preIndex] <= maxi)
    {
        // curr root value, increment for next node traversal
        int root = arr[preIndex];
        preIndex++;

        // left subtree will have value ranging b/w mini...root
        // right subtree will have value ranging b/w root...maxi
        solve(preIndex, n, arr, mini, root);
        solve(preIndex, n, arr, root, maxi);
    }
}

//! TC is O(n)
//! SC is O(n)

bool canRepresentBST(vector<int> &arr)
{
    int n = arr.size();

    // keep track of the min and max range for every node
    int mini = INT_MIN, maxi = INT_MAX;

    // start from the first element as the root
    int preIndex = 0;

    solve(preIndex, n, arr, mini, maxi);

    // all node values have been visited -> valid BST
    return preIndex == n;
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 4, 6};
    cout << canRepresentBST(arr);
}