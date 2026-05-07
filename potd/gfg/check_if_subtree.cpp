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
        left = right = nullptr;
    }
};

bool isValid(Node *root1, Node *root2)
{
    // base case: both are null -> return true
    if (!root1 && !root2)
        return true;

    // base case
    if (!root1 || !root2)
        return false;

    // node's are not same -> return false
    if (root1->data != root2->data)
        return false;

    // recurse for left and right subtree
    return isValid(root1->left, root2->left) && isValid(root1->right, root2->right);
}

//! TC is O(n + m)
//! SC is O(n + m)

bool isSubTree(Node *root1, Node *root2)
{
    // base case
    if (!root1 || !root2)
        return false;

    // queue for BFS traversal
    queue<Node *> q;
    q.push(root1);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        // if curr node data == 2nd tree's root data -> start the dfs traversal
        if (node->data == root2->data)
        {
            if (isValid(node, root2))
                return true;
        }

        // push the curr node left and right child
        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }

    // 2nd tree is not a subtree of 1st one -> return false
    return false;
}

int main()
{
    // Construct Tree root1
    //          26
    //         /  \
    //        10   3
    //       / \    \
    //      4   6    3
    //       \
    //        30
    Node *root1 = new Node(26);
    root1->left = new Node(10);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(6);
    root1->left->left->right = new Node(30);
    root1->right->right = new Node(3);

    // Construct Tree root2
    //          10
    //         /  \
    //        4    6
    //         \
    //          30
    Node *root2 = new Node(10);
    root2->left = new Node(4);
    root2->right = new Node(6);
    root2->left->right = new Node(30);

    cout << (isSubTree(root1, root2) ? "true" : "false");

    return 0;
}