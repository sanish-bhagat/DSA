#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int findLevel(Node *root, int k, int level)
{
    if (!root)
        return -1;

    if (root->data == k)
        return level;

    int leftlvl = findLevel(root->left, k, level + 1);

    if (leftlvl != -1)
        return leftlvl;

    else
        return findLevel(root->right, k, level + 1);
}

Node *LCA(Node *root, int a, int b)
{
    if (!root)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node *leftlca = LCA(root->left, a, b);
    Node *rightlca = LCA(root->right, a, b);

    if (leftlca == NULL)
        return rightlca;

    else if (rightlca == NULL)
        return leftlca;

    else
        return root;
}

//! TC is O(n)
//! SC is O(h)

int findDist(Node *root, int a, int b)
{
    // find the lca of the two nodes
    Node *lca = LCA(root, a, b);

    // find the dist of the nodes from the lca
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}

int main()
{

    // Hardcoded binary tree
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a = 4, b = 7;
    cout << findDist(root, a, b) << endl;

    return 0;
}