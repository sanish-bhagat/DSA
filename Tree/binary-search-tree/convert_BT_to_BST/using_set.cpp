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
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *root, set<int> &nodes)
{
    if (root == NULL)
        return;

    inorder(root->left, nodes);

    nodes.insert(root->data);

    inorder(root->right, nodes);
}

void constructBST(Node *root, set<int> &nodes)
{
    if (root == NULL)
        return;

    constructBST(root->left, nodes);

    // get the first element of the set and update original root value, make sure to remove the item from the set
    int val = *nodes.begin();
    nodes.erase(nodes.begin());
    root->data = val;

    constructBST(root->right, nodes);
}

//! TC is O(n * logn)
//! SC is O(n)

Node *binaryTreeToBST(Node *root)
{
    // set stores the value in sorted order
    set<int> nodes;
    inorder(root, nodes);

    // construct the tree recursively
    constructBST(root, nodes);

    return root;
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{

    // Creating the tree
    //         10
    //        /  \
    //       2    7
    //      / \
    //     8   4
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);

    Node *ans = binaryTreeToBST(root);
    printInorder(ans);

    return 0;
}