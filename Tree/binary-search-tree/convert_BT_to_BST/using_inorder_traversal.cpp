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

// recursively store the inorder traversal of the given binary tree
void inorder(Node *root, vector<int> &nodes)
{
    if (root == NULL)
        return;

    inorder(root->left, nodes);

    nodes.push_back(root->data);

    inorder(root->right, nodes);
}

// recursively construct the BST using sorted inorder array
void constructBST(Node *root, vector<int> &nodes, int &index)
{
    if (!root)
        return;

    constructBST(root->left, nodes, index);

    root->data = nodes[index++];

    constructBST(root->right, nodes, index);
}

//! TC is O(n * logn)
//! SC is O(n)

Node *binaryTreeToBST(Node *root)
{
    vector<int> nodes;

    // get the inorder of the given tree
    inorder(root, nodes);

    // sort the inorder array to construct the BST
    sort(nodes.begin(), nodes.end());

    int index = 0;
    constructBST(root, nodes, index);
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