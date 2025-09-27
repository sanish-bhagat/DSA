#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//! TC is O(n)
//! SC is O(1)

vector<int> inOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> res;
    Node *curr = root;

    while (curr != NULL)
    {
        //left not exist, visit the node and move right
        if (curr->left == NULL)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else    //left exists
        {
            Node *prev = curr->left;

            //find the inorder predecessor(rightmost node of the left subtree)
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;

            //create a thread and move to right
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }

            //if thread exists and the right pointer is pointing to curr then first remove the thread, visit the node and move to right
            else
            {
                prev->right = NULL;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return res;
}

int main()
{

    // Constructed binary tree is
    //          1
    //        /   \
    //      2      3
    //    /  \
    //  4     5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}