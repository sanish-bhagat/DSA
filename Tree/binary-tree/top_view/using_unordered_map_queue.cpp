#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

//! TC i O(n)
//! SC is O(n)

vector<int> topView(Node *root)
{
    if (!root)
        return {};

    unordered_map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    Node *temp = NULL;
    int mn = INT_MAX;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        temp = it.first;
        int d = it.second;

        // keep track of the min horizontal distance
        mn = min(mn, d);

        if (mpp.find(d) == mpp.end())
            mpp[d] = temp->data;

        if (temp->left)
            q.push({temp->left, d - 1});

        if (temp->right)
            q.push({temp->right, d + 1});
    }

    vector<int> res(mpp.size());

    // pushing the nodes value of the map in correct order into res by using mn(minimum horizontal distance),
    // mn helps in correct indexing while pushing in res array
    for (auto it = mpp.begin(); it != mpp.end(); it++)
        res[(it->first) - mn] = (it->second);

    return res;
}

int main()
{

    // Create a sample binary tree
    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}