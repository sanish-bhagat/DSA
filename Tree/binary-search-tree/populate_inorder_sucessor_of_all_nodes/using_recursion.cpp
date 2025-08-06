#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node *next;
};

node *newnode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;

    return (Node);
}

void populateNextRec(node *root, node *&prev)
{
    if (!root)
        return;

    // set the next ptr int the left subtree
    populateNextRec(root->left, prev);

    // set the next ptr of the prev node to the curr node
    // as the inorder successor of the prev node
    if (prev)
        prev->next = root;

    // update the prev node as the curr node for the next upcoming traversal
    prev = root;

    // set the next ptr in the right subtree
    populateNextRec(root->right, prev);
}

//! TC is O(n)
//! SC is O(h)

void populateNext(node *root)
{
    // prev pointer to link the curr node with its inorder succesor
    node *prev = NULL;
    populateNextRec(root, prev);
}

// Driver Code
int main()
{

    /* Constructed binary tree is
            10
            / \
        8 12
        /
    3
    */
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    node *ptr = root->left->left;
    while (ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }

    return 0;
}