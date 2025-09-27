#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

vector<int> preOrder(Node *root)
{
    vector<int> res;

    Node *curr = root;

    while (curr != NULL)
    {
        // visit the node and move to right
        if (curr->left == NULL)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else // left child exists
        {
            Node *prev = curr->left;

            // find the inorder predecessor
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            // visit the node, create the thread and move to the left of the curr node
            if (prev->right == NULL)
            {
                res.push_back(curr->data);
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // remove the thread and move to the right pf the curr node
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preOrder(root);

    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}