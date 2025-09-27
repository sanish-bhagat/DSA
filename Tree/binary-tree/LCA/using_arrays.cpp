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

bool findPath(Node *root, vector<Node *> &path, int k)
{
    if (!root)
        return false;

    // push the curr node into the path
    path.push_back(root);

    // if curr data == to the desired node, or node exost int left or right subtree, then return true
    if (root->data == k || findPath(root->left, path, k) || findPath(root->right, path, k))
        return true;

    // backtrack the array
    path.pop_back();
    return false;
}

//! TC is O(n)
//! SC is O(n)

Node *lca(Node *root, int n1, int n2)
{
    // separate arrays to store the path from root to nodes
    vector<Node *> path1, path2;

    // find path of n1 and n2 nodes from the root, if either n1 or n2 path doesn't exist return NULL
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return NULL;

    // compare the paths and find the lca by finding the first different value
    // when different value is encountered, lca will be the prev value of this different one
    int i = 0;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
            return path1[i - 1];
    }

    // if bothe the datas are same return the last node of the array
    return path1[i - 1];
}

int main()
{

    // construct the binary tree
    //			   1
    //           /   \
    //          2     3
    //         / \   / \
    //        4  5  6   7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *ans = lca(root, 4, 5);
    if (ans == nullptr)
        cout << "No common ancestor found";
    else
        cout << ans->data;
    return 0;
}