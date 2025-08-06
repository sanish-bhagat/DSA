#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

bool isBST(Node *root)
{
    // to track the inorder predecessor
    Node *curr = root;

    // to get track of the prev value encountered
    Node *prev = NULL;
    int prevVal = INT_MIN;

    // traverse the tree
    while (curr)
    {
        if (curr->left == NULL)
        {

            // check if it violates the BST property,
            // inorder traversal values' are not in ascending order
            if (curr->data <= prevVal)
                return false;

            // update preValue and move curr to its right child
            prevVal = curr->data;
            curr = curr->right;
        }

        // if left exists then find the inorder predecessor
        else
        {
            prev = curr->left;

            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            // make a temp linkage with curr
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }

            else
            {
                // remove the temp linkage
                prev->right = NULL;

                // process the inorder property
                if (curr->data <= prevVal)
                    return false;

                // update prevvalue and move curr to its right child
                prevVal = curr->data;
                curr = curr->right;
            }
        }
    }

    return true;
}

int main()
{

    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}