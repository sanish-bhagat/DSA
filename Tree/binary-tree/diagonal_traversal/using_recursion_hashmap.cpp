#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void diagonalRec(Node *root, int level, unordered_map<int, vector<int>> &mpp)
{
    if (!root)
        return;

    // map the curr node data to the curr level
    mpp[level].push_back(root->data);

    // left child increases the diagonal level
    diagonalRec(root->left, level + 1, mpp);

    // right child reminas on the same level
    diagonalRec(root->right, level, mpp);
}

//! TC is O(n)
//! SC is O(n)

vector<int> diagonal(Node *root)
{
    if (!root)
        return {};

    unordered_map<int, vector<int>> mpp;

    diagonalRec(root, 0, mpp);

    int level = 0;
    vector<int> res;

    while (mpp.find(level) != mpp.end())
    {
        // get the nodes of each level
        vector<int> v = mpp[level];

        for (int i = 0; i < v.size(); i++)
            res.push_back(v[i]);

        level++;
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

    // Create a hard coded tree
    //         8
    //       /   \
    //     3      10
    //    /      /  \
    //   1      6    14
    //         / \   /
    //        4   7 13
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    vector<int> ans = diagonal(root);
    printList(ans);
}