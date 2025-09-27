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

pair<bool, int> calculateDist(Node *root, int a, int b, int &dist)
{
    if (!root)
        return {false, 0};

    // check if curr node is one of the two nodes
    bool current = (root->data == a || root->data == b);

    // recursive calls fro left and right subtree
    pair<bool, int> left = calculateDist(root->left, a, b, dist);
    pair<bool, int> right = calculateDist(root->right, a, b, dist);

    // If current node is one of n1 or n2 and
    // we found the other in a subtree, update distance
    if (current && (left.first || right.first))
    {
        dist = max(left.second, right.second);
        return {false, 0};
    }

    // If left and right both returned true,
    // root is the LCA and we update the distance
    if (left.first && right.first)
    {
        dist = left.second + right.second;
        return {false, 0};
    }

    // If either left or right subtree contains n1 or n2,
    // return the updated distance
    if (left.first || right.first || current)
    {
        return {true, max(left.second, right.second) + 1};
    }

    // If neither n1 nor n2 exist in the subtree
    return {false, 0};
}

//! TC is O(n)
//! SC is O(h)

int findDist(Node *root, int a, int b)
{
    int dist = 0;
    calculateDist(root, a, b, dist);
    return dist;
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