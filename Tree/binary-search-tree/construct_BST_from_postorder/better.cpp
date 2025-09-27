//? Find the first greater element than root

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

Node *constructBST(vector<int> &pre, int low, int high)
{
    if (low > high)
        return NULL;

    // Create the root node with the first element
    // in the current range
    Node *root = new Node(pre[low]);

    if (low == high)
        return root;

    // Find the first element greater than root to
    // divide the array
    int i = low + 1;
    while (i <= high && pre[i] <= root->data)
        i++;

    // recursivelly construct left and right subtrees
    root->left = constructBST(pre, low + 1, i - 1);
    root->right = constructBST(pre, i, high);

    return root;
}

//! TC is O(n * n)
//! SC is O(n)

Node *construct(vector<int> &pre)
{
    return constructBST(pre, 0, pre.size() - 1);
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