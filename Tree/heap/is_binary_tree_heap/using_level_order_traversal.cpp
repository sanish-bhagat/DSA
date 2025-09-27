#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int k)
    {
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

bool isHeap(Node *root)
{
    queue<Node *> q;
    q.push(root);

    // to track the null child, there will only be only null child, as it is a complete tree
    bool nullChildSeen = false;

    // traverse the tree
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            // if any condn gets violated then its not a heap
            if (nullChildSeen || curr->left->data > curr->data)
                return false;

            // else push the left child into the queue
            q.push(curr->left);
        }
        else
            // update the flag, once a null child is seen, then all subsequent nodes must be leaves
            nullChildSeen = false;

        if (curr->right)
        {
            // if any condn gets violated then its not a heap
            if (nullChildSeen || curr->right->data > curr->data)
                return false;

            // else push the right child into the queue
            q.push(curr->right);
        }
        else
            nullChildSeen = false;
    }

    return true;
}

int main()
{

    // Construct the Binary Tree
    //        10
    //       /  \
    //      9    8
    //     / \   / \
    //    7   6 5   4

    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if (isHeap(root))
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}