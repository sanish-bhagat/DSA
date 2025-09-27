#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// utility that allocates a new Node with the given key
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

//! TC is O(n)
//! SC is O(n)

void flatten(Node *root)
{
    // base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    // if left child exist then make it the right child
    if (root->left != NULL)
    {

        // recursive call for the left child
        flatten(root->left);

        // change the link - make left child as the right child
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        // find the position to insert the store value(temp)
        Node *t = root->right;
        while (t->right != NULL)
            t = t->right;

        // insert the stored value
        t->right = temp;
    }

    // call for the right child
    flatten(root->right);
}

void inorder(struct Node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
    /*    1
        /   \
       2     5
      / \     \
     3   4     6 */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
    flatten(root);
    cout << "The Inorder traversal after flattening binary tree ";
    inorder(root);
    return 0;
}
