#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int k)
    {
        data = k;
        left = right = nullptr;
    }
};

//! ONE traversal
//! TC is O(h)
//! SC is O(h)

Node *delNode(Node *root, int key)
{
    if (!root)
        return NULL;

    // key is in the left subtree
    if (root->data > key)
    {
        root->left = delNode(root->left, key);
    }

    // key is in the right subtree
    else if (root->data < key)
        root->right = delNode(root->right, key);

    // key is found
    else
    {
        // node has 0 children
        // only right child exists
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // only left child exists
        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // both children are present -> find the succ of the node
        // copy the succ -> data into node data, and then
        // delete that succ node

        // keep track of the parent of the succ
        Node *succParent = root;

        Node *succ = root->right;
        while (succ && succ->left)
        {
            succParent = succ;
            succ = succ->left;
        }

        root->data = succ->data;

        // succ will only have right child
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
    }

    return root;
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    root = delNode(root, x);
    inorder(root);
    return 0;
}