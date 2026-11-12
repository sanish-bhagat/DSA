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
        left = NULL;
        right = NULL;
    }
};

//! TC is O(h)
//! SC is O(h)

int minDiff(Node *root, int k)
{
    int res = INT_MAX;
    Node *curr = root;

    // traverse the BST using its property
    while (curr)
    {
        // find the min abs diff
        res = min(res, abs(curr->data - k));

        // move to the left node
        if (curr->data > k)
            curr = curr->left;

        // move to the right node
        else
            curr = curr->right;
    }

    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(6);
    root->left->right->left->right = new Node(4);

    int k = 13;

    cout << minDiff(root, k);

    return 0;
}