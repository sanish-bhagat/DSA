#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// index 0 -> min value, 1 -> max value, 2 -> size of the BST

vector<int> largestBstUtil(Node *root)
{
    // base case - treats an empty subtree as valid BST
    if (!root)
        return {INT_MAX, INT_MIN, 0};

    // leaf node is a valid BST of size 1
    if (!root->left && !root->right)
        return {root->data, root->data, 1};

    // recursive calls
    vector<int> left = largestBstUtil(root->left);
    vector<int> right = largestBstUtil(root->right);

    vector<int> ans(3);

    // if valid BST then get the max size of the valid BST
    if (left[1] < root->data && right[0] > root->data)
    {
        ans[0] = min(left[0], root->data);
        ans[1] = max(root->data, right[1]);
        ans[2] = 1 + left[2] + right[2];
        return ans;
    }

    ans[0] = INT_MIN;
    ans[1] = INT_MAX;
    ans[2] = max(left[2], right[2]);
    return ans;
}

//! TC is O(n)
//! SC is O(n)

int largestBst(Node *root)
{
    return largestBstUtil(root)[2];
}

int main()
{

    // Constructed binary tree looks like this:
    //         50
    //       /    \
    //     75      45
    //    /
    //  40

    Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);

    cout << largestBst(root) << endl;
    return 0;
}