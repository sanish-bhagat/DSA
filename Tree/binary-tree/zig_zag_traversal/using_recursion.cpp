#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int heightOfTree(Node *root)
{
    if (!root)
        return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return 1 + max(left, right);
}

void getLeftToRight(Node *root, int level, vector<int> &res)
{
    if (!root)
        return;

    if (level == 1)
        res.push_back(root->data);

    else
    {
        // first go to left subtree then to the right subtree
        getLeftToRight(root->left, level - 1, res);
        getLeftToRight(root->right, level - 1, res);
    }
}

void getRightToLeft(Node *root, int level, vector<int> &res)
{
    if (!root)
        return;

    if (level == 1)
        res.push_back(root->data);

    else
    {
        // first go to right subtree then to the left subtree
        getRightToLeft(root->right, level - 1, res);
        getRightToLeft(root->left, level - 1, res);
    }
}

//! TC is O(n)
//! SC is O(n)

vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};

    int height = heightOfTree(root);
    bool leftToRight = true;
    vector<int> res;

    for (int i = 1; i <= height; i++)
    {
        if (leftToRight)
            getLeftToRight(root, i, res);

        else
            getRightToLeft(root, i, res);

        leftToRight = !leftToRight;
    }

    return res;
}

void printList(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    vector<int> ans = zigZagTraversal(root);
    printList(ans);

    return 0;
}