#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// DFS traversal
bool findPath(Node *root, vector<Node *> &path, int node)
{
    if (!root)
        return false;

    path.push_back(root);

    // if node found no further computation
    if (root->data == node)
        return true;

    // if left and rigt recursive call return true, then return true
    if (findPath(root->left, path, node) || findPath(root->right, path, node))
        return true;

    // backtrack
    path.pop_back();
    return false;
}

//! TC is O(n)
//! SC is O(h)

int kthAncestor(Node *root, int k, int node)
{
    vector<Node *> path;

    // if no path is found between root and node, return -1
    if (!findPath(root, path, node))
        return -1;

    // initialise the index of the kth ancestor of the node
    int index = path.size() - k - 1;

    // if index becomes -ve, means no kth ancestor is present for the node then return -1
    if (index < 0)
        return -1;

    // return the data present in the path[index]
    return path[index]->data;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    cout << kthAncestor(root, k, node);
    return 0;
}