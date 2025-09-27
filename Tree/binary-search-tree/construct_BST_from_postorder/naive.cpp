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

Node *constructBST(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    // element belongs to left subtree
    if (root->data > key)
        root->left = constructBST(root->left, key);

    // element belongs to right subtree
    else if (root->data < key)
        root->right = constructBST(root->right, key);

    return root;
}

//! TC is O(n * n)
//! SC is O(n)

Node *construct(vector<int> &pre)
{
    Node *root = NULL;

    // traversing pre[] and inserting elements one by one  into BST
    for (int key : pre)
        root = constructBST(root, key);

    return root;
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