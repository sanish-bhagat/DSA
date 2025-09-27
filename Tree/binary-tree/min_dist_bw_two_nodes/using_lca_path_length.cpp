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
    if (root == NULL)
        return -1;

    // if node is found return the level
    if (root->data == k)
        return level;

    // check in the left subtree
    int left = findLevel(root->left, k, level + 1);

    // if node found in left subtree then return level, else check in the right subtree
    if (left != -1)
        return left;

    else
        return findLevel(root->right, k, level + 1);
}

Node *findLcaAndDistance(Node *root, int a, int b, int &d1, int &d2, int &dist, int level)
{
    if (!root)
        return NULL;

    // if first node is found, store the dist or level and return the root
    if (root->data == a)
    {
        d1 = level;
        return root;
    }

    // if second node is found stir ethe level and return the root
    if (root->data == b)
    {
        d2 = level;
        return root;
    }

    // recursive call for left and right child
    Node *left = findLcaAndDistance(root->left, a, b, d1, d2, dist, level + 1);
    Node *right = findLcaAndDistance(root->right, a, b, d1, d2, dist, level + 1);

    // if both nodes are found in different subtrees, calculate the dist
    if (left != NULL && right != NULL)
        dist = d1 + d2 - 2 * level;

    // return whichever node found
    if (left != NULL)
        return left;

    else
        return right;
}

//! TC is O(n)
//! SC is O(h)

int findDist(Node *root, int a, int b)
{
    int d1 = -1, d2 = -1, dist;

    // find lca and calculate dist
    Node *lca = findLcaAndDistance(root, a, b, d1, d2, dist, 0);

    // return distance if both nodes are found
    if (d1 != -1 && d2 != -1)
        return dist;

    // if only first node is found find the distance to the second node
    if (d1 != -1)
    {
        dist = findLevel(lca, b, 0);
        return dist;
    }

    // if only second node is found find the distance to the first node
    if (d2 != -1)
    {
        dist = findLevel(lca, a, 0);
        return dist;
    }

    // return -1, if both distance are not found
    return -1;
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