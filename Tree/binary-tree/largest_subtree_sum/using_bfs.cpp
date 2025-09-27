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

//! TC is O(n)
//! SC is O(n)

int findLargestSubtreeSum(Node *root)
{
    if (!root)
        return 0;

    // to traverse the tree
    queue<Node *> q;
    q.push(root);

    // to store the nodes according to their levels
    vector<vector<Node *>> levels;

    // to map the curr subtreesum of each node
    unordered_map<Node *, int> subtreeSum;
    int ans = INT_MIN;

    while (!q.empty())
    {
        int n = q.size();

        vector<Node *> level;
        while (n--)
        {
            Node *node = q.front();
            q.pop();

            // push the nodes in this curr level to the vector
            level.push_back(node);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        // push the pushed level into levels vector
        levels.push_back(level);
    }

    // traverse the container in reverse
    for (int i = levels.size() - 1; i >= 0; i--)
    {
        for (auto e : levels[i])
        {
            // add value of curr node
            subtreeSum[e] = e->data;

            // if left or right child, then add the subtreesum into the currSum
            if (e->left)
                subtreeSum[e] += subtreeSum[e->left];

            if (e->right)
                subtreeSum[e] += subtreeSum[e->right];

            // update the ans
            ans = max(ans, subtreeSum[e]);
        }
    }

    return ans;
}

int main()
{

    // Representation of the given tree
    //          1
    //        /   \
    //      -2     3
    //      / \   / \
    //     4   5 -6  2
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}