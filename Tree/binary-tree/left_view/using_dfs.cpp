#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void getLeftView(Node *root, int currLevel, int &maxLevel, vector<int> &res)
{
    if (root == NULL)
        return;

    // if the curr node is the first visited node in its level then push it
    if (currLevel > maxLevel)
    {
        res.push_back(root->data);
        maxLevel = currLevel;
    }

    getLeftView(root->left, currLevel + 1, maxLevel, res);
    getLeftView(root->right, currLevel + 1, maxLevel, res);
}

//! TC is O(n)
//! Sc is O(h)

vector<int> leftView(Node *root)
{
    vector<int> res;
    int maxLevel = -1;

    getLeftView(root, 0, maxLevel, res);

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> view = leftView(root);

    for (int val : view)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}