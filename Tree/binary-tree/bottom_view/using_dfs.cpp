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
        left = right = nullptr;
    }
};

void dfs(Node *root, int hd, int depth, map<int, pair<int, int>> &mpp)
{
    if (!root)
        return;

    // if it is the first node of the horizonatl distamce
    // or the height/depth of the new node is greater than the existing one,push into the map
    if (mpp.find(hd) == mpp.end() || depth >= mpp[hd].second)
        mpp[hd] = {root->data, depth};

    dfs(root->left, hd - 1, depth + 1, mpp);
    dfs(root->right, hd + 1, depth + 1, mpp);
}

//! TC is O(n * logn)
//! SC is O(n)

vector<int> bottomView(Node *root)
{
    if (!root)
        return {};

    map<int, pair<int, int>> mpp;

    dfs(root, 0, 0, mpp);

    vector<int> res;

    for (auto it : mpp)
        res.push_back(it.second.first);

    return res;
}

void printArray(vector<int> &arr)
{

    cout << endl;
}

int main()
{

    // Representation of the input tree:
    //       20
    //      /  \
    //     8   22
    //    / \    \
    //   5   3   25
    //      / \
    //     10 14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> result = bottomView(root);
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}