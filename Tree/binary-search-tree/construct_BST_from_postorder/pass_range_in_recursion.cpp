#include <bits/stdc++.h>
using namespace std;

struct Node
{
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

Node *constructBST(vector<int> &pre, int &idx, int min, int max)
{
    if (idx >= pre.size())
        return NULL;

    int key = pre[idx];

    // if element is out of range return NULL
    if (key <= min || key >= max)
        return NULL;

    // create the node for the element and move forward
    Node *root = new Node(key);
    idx++;

    // recursively construct the left and right subtree by updating the range
    //  elements between (min ... key) lies in left subtree
    //  elements between (key ... max) lies in right subtree
    if (idx < pre.size())
        root->left = constructBST(pre, idx, min, key);

    if (idx < pre.size())
        root->right = constructBST(pre, idx, key, max);

    return root;
}

//! TC is O(n)
//! SC is O(n)

Node *construct(vector<int> &pre)
{
    int idx = 0;
    return constructBST(pre, idx, INT_MIN, INT_MAX);
}

void printInorder(Node *root)
{
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Driver code
int main()
{
    vector<int> pre = {10, 5, 1, 7, 40, 50};
    Node *root = construct(pre);
    printInorder(root);
    return 0;
}