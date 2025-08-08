#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int kthAncestor(Node *root, int k, int node)
{
    stack<Node *> s;
    vector<int> ancestors;

    bool found = false;

    while (root != NULL || !s.empty())
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        else
        {
            Node *curr = s.top();
            s.pop();

            if (curr->data == node)
            {
                found = true;
                break;
            }

            if (curr->right)
            {
                root = curr->right;
            }
        }
    }

    if (!found)
        return -1;

    while (!s.empty() && k > 0)
    {
        Node *temp = s.top();
        s.pop();
        ancestors.push_back(temp->data);
        k--;
    }

    if (k > 0)
        return -1;

    return ancestors.back();
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    cout << kthAncestor(root, k, node);
    return 0;
}