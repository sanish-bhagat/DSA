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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void collectNode(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;

    // if it is the curr last level
    if (level == 1)
        res.push_back(root->data);

    else
    {
        collectNode(root->left, level - 1, res);
        collectNode(root->right, level - 1, res);
    }
}

//! TC is O(n * n)
//! SC is O(1)

vector<int> reverseLevelOrder(Node *root)
{
    int h = height(root);

    vector<int> res;

    for (int i = h; i >= 1; i--)
        collectNode(root, i, res);

    return res;
}

int main()
{
    /*
        Tree Structure:
            1
           / \
          3   2
    */
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    vector<int> result = reverseLevelOrder(root);

    cout << "Reverse Level Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}