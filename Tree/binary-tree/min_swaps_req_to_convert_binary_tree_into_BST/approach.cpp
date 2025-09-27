#include <bits/stdc++.h>
using namespace std;

void getInorder(vector<int> &arr, vector<int> &inorder, int index)
{
    int n = arr.size();

    // if index is out of range, return
    if (index >= n)
        return;

    // recursive call for the left child
    getInorder(arr, inorder, 2 * index + 1);

    inorder.push_back(arr[index]);

    // recursive call for the right child
    getInorder(arr, inorder, 2 * index + 2);
}

// inorder of BST is in increasing order of their value
//! TC is O(n * logn)
//! SC is O(n)

int minSwaps(vector<int> &arr)
{

    // find the  inorder of the binary tree
    vector<int> inorder;
    getInorder(arr, inorder, 0);

    // array of pairs to store the value with their original indices
    vector<pair<int, int>> t;

    // copy the value of the inorder array into pair of arrays alogn with their indices
    for (int i = 0; i < inorder.size(); i++)
        t.push_back({inorder[i], i});

    // sort the array of pairs based on values to get the order of BST
    sort(t.begin(), t.end());

    // swap count
    int ans = 0;

    // find the min swaps
    for (int i = 0; i < t.size(); i++)
    {
        // if the value is in correct position, continue(move to the next iteration)
        if (i == t[i].second)
            continue;

        // swap the elements to their correct position
        else
        {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        // after swapping if the element is still not in correct position, then decrement i
        if (i != t[i].second)
            i--;

        // increment the swap count
        ans++;
    }

    return ans;
}

int main()
{

    vector<int> arr = {5, 6, 7, 8, 9, 10, 11};
    cout << minSwaps(arr) << endl;
}