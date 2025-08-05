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
//! SC is O(1)

void flatten(Node *root)
{
    while (root)
    {
        // if left exists find the inorder predecessor
        if (root->left)
        {
            Node *curr = root->left;

            // find the inorder predecessor
            while (curr->right)
                curr = curr->right;

            // set the right child of the predecessor to the right child of the root
            curr->right = root->right;

            // set the right pf the root to its left child
            root->right = root->left;

            // set the left child of th root to be NULL
            root->left = NULL;
        }

        // move to the next node
        root = root->right;
    }
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
