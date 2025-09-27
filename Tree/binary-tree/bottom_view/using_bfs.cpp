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

//! TC is O(n * logn)
//! SC is O(n)

vector<int> bottomView(Node *root)
{
    if (!root)
        return {};

    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *curr = it.first;
        int hd = it.second;

        // keep updating the value in the map
        mpp[hd] = curr->data;

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    vector<int> res;

    for (auto it : mpp)
        res.push_back(it.second);

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