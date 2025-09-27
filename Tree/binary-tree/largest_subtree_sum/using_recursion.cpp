#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

int findLargestSubtreeSumRec(Node *root, int &ans)
{
    if (!root)
        return 0;

    // get the sum of the left and right subtree
    int left = findLargestSubtreeSumRec(root->left, ans);
    int right = findLargestSubtreeSumRec(root->right, ans);

    // calculate the curr subtree sum
    int currSum = root->data + left + right;

    // update the ans with the max sum do far
    ans = max(ans, currSum);

    // return the currSum to the above subtree
    return currSum;
}

//! TC is O(n)
//! SC is O(h)

int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;

    int ans = INT_MIN;

    findLargestSubtreeSumRec(root, ans);

    return ans;
}

int main()
{

    // Representation of the given tree
    //          1
    //        /   \
    //      -2     3
    //      / \   / \
    //     4   5 -6  2
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}