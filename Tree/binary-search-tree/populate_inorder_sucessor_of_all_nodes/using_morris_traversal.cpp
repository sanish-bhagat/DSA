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

//! TC is O(n)
//! SC is O(1)

void populateNext(node *root)
{
    node *curr = root;
    node *prev = NULL;

    // traverse the tree
    while (curr)
    {
        // if left not exists, then set the link of prev node and move to right
        if (!curr->left)
        {
            if (prev)
                prev->next = curr;

            prev = curr;
            curr = curr->right;
        }
        else
        {
            // find the inorder predecessor of the curr node
            node *pred = curr->left;

            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;

            // create the thread b/w pred and curr
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // if the node is traversed two times then remove the thread and set prev -> next to curr and move right
            else
            {
                pred->right = NULL;

                if (prev)
                    prev->next = curr;

                prev = curr;
                curr = curr->right;
            }
        }
    }
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