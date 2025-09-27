#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

void inorder(node *root, node *&prev) {
    if(!root)
        return;

    inorder(root -> left, prev);

    //set the link for the correct order of sorted list
    prev -> left = NULL;
    prev -> right = root;
    prev = root;

    inorder(root -> right, prev);
}

//! TC is O(n)
//! SC is O(h)

node *flatten(node *root) {
    node *dummy = new node(-1);
    node *prev = dummy;

    inorder(root, prev);

    //set the ptr of last node to NULL
    prev -> right = prev -> left = NULL;

    //return the head of the sorted list
    node *ret = dummy -> right;

    delete dummy;
    return ret;
}

int main()
{

    node* root = new node(5);
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