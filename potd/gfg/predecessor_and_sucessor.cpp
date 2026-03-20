#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// gives the leftmost(min) node for the curr node
Node *leftMost(Node *node)
{
    while (node->left)
        node = node->left;

    return node;
}

// gives the rightmost(min) node for the curr node
Node *rightMost(Node *node)
{
    while (node->right)
        node = node->right;

    return node;
}

//! TC is O(n)
//! SC is O(1)

vector<Node *> findPreSuc(Node *root, int key)
{
    Node *pred = NULL, *suc = NULL, *curr = root;

    while (curr)
    {
        // potential predecessor
        if (curr->data < key)
        {
            pred = curr;

            // move right to look for larger values
            curr = curr->right;
        }

        // potential successor
        else if (curr->data > key)
        {
            suc = curr;

            // move left to look for smaller values
            curr = curr->left;
        }

        // key == curr, pred is the max in left subtree and
        // succ is the min in the right subtree
        else
        {
            if (curr->left)
                pred = rightMost(curr->left);

            if (curr->right)
                suc = leftMost(curr->right);

            break;
        }
    }

    // return the predecessor and successor of the given key
    return {pred, suc};
}

int main()
{
    int key = 65;

    // Create BST:
    //      50
    //     /  \
    //   30     70
    //   / \    / \
    // 20  40  60  80

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    vector<Node *> result = findPreSuc(root, key);
    Node *pre = result[0];
    Node *suc = result[1];

    cout << (pre ? to_string(pre->data) : "NULL") << " ";
    cout << (suc ? to_string(suc->data) : "NULL");
}