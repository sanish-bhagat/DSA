#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to print flattened
// binary Tree
void print(node *parent)
{
    node *curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

void inorder(node *root, vector<int> &traversal)
{
    if (!root)
        return;

    inorder(root->left, traversal);

    traversal.push_back(root->data);

    inorder(root->right, traversal);
}

void form(int pos, node *&prev, vector<int> traversal)
{
    if (pos == traversal.size())
        return;

    // create a new node of the element, and make the left ptr of every node to null
    prev->right = new node(traversal[pos]);
    prev->left = NULL;

    // move to the next node for the recurisve call
    prev = prev->right;

    // recursivelly create the sorted list
    form(pos + 1, prev, traversal);
}

//! TC is O(n)
//! SC is O(n)

node *flatten(node *root)
{
    // find the inorder of the BST
    vector<int> traversal;
    inorder(root, traversal);

    // create a dummy node for the new list
    node *dummy = new node(-1);

    node *prev = dummy;

    // create the sorted list using inorder array
    form(0, prev, traversal);

    // point the last node ptrs to null
    prev->right = NULL;
    prev->left = NULL;

    // return the head of the BST
    node *ret = dummy->right;

    delete dummy;
    return ret;
}

int main()
{

    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // Calling required function
    print(flatten(root));

    return 0;
}