#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

int distRec(Node *root, int &ans)
{
    if (!root)
        return 0;

    // traverse the left and right subtree
    int l = distRec(root->left, ans);
    int r = distRec(root->right, ans);

    // no. of candies from left and right subtree
    ans += abs(l) + abs(r);

    // no. of moves to balance curr node
    return root->data + l + r - 1;
}

//! TC is O(n)
//! SC is O(h)

int distCandy(Node *root)
{
    int ans = 0;

    // recursively calculate the total no. of moves required to balance the tree
    distRec(root, ans);

    return ans;
}

int main()
{

    // Representation of given Binary Tree
    //        5
    //       / \
//      0   0
    //         / \
//        0   0
    Node *root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);

    cout << distCandy(root);

    return 0;
}