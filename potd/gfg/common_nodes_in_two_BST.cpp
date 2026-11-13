#include <bits/stdc++.h>
using namespace std;

// Structure of a BST node.
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

// Insert a node into the BST.
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

//! TC is O(n1 + n2)
//! SC is O(h1 + h2)

vector<int> findCommon(Node *r1, Node *r2)
{
    vector<int> res;

    // stacks for simultaneous inorder traversal of both BSTs
    stack<Node *> s1, s2;

    while (true)
    {
        // push all left nodes of BST-1
        while (r1)
        {
            s1.push(r1);
            r1 = r1->left;
        }

        // push all right nodes of BST-2
        while (r2)
        {
            s2.push(r2);
            r2 = r2->left;
        }

        // if either stack is empty, no more common nodes can exist
        if (s1.empty() || s2.empty())
            break;

        Node *top1 = s1.top();
        Node *top2 = s2.top();

        // common node found
        if (top1->data == top2->data)
        {
            res.push_back(top1->data);

            s1.pop();
            s2.pop();

            // move to right subtrees
            r1 = top1->right;
            r2 = top2->right;
        }

        // advance in BST-1
        else if (top1->data < top2->data)
        {
            s1.pop();
            r1 = top1->right;
            r2 = NULL; // same left nodes should not be traversed again from BST-2
        }

        // advacne in BST-2
        else
        {
            s2.pop();
            r2 = top2->right;
            r1 = NULL; // same left nodes should not be traversed again from BST-1
        }
    }

    return res;
}

int main()
{

    // First BST
    //
    //          5
    //        /   \
    //       1     10
    //      / \    /
    //     0   4  7
    //            \
    //             9
    //
    Node *r1 = nullptr;
    r1 = insert(r1, 5);
    r1 = insert(r1, 1);
    r1 = insert(r1, 10);
    r1 = insert(r1, 0);
    r1 = insert(r1, 4);
    r1 = insert(r1, 7);
    r1 = insert(r1, 9);

    // Second BST
    //
    //        10
    //       /  \
    //      7    20
    //     / \
    //    4   9
    //
    Node *r2 = nullptr;
    r2 = insert(r2, 10);
    r2 = insert(r2, 7);
    r2 = insert(r2, 20);
    r2 = insert(r2, 4);
    r2 = insert(r2, 9);

    vector<int> res = findCommon(r1, r2);

    // Print the array.
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}