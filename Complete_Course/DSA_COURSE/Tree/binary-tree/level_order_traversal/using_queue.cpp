#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<vector<int>> levelOrder(Node *root)
{
    // base case
    if (root == NULL)
        return {};

    queue<Node *> q;
    vector<vector<int>> res;

    // pus the root node
    q.push(root);
    int currLevel = 0;

    while (!q.empty())
    {
        // find the size of the queue to traverse all the nodes present in it
        int len = q.size();

        // create a new level in res
        res.push_back({});

        // traverse the nodes present in queue
        for (int i = 0; i < len; i++)
        {
            // pop the front node
            Node *node = q.front();
            q.pop();

            // push the popped node's data at the currlevel in res
            res[currLevel].push_back(node->data);

            // enqueue the left child
            if (node->left)
                q.push(node->left);

            // enqueue the right child
            if (node->right)
                q.push(node->right);
        }
        // increase the curr level after traversing the prev one
        currLevel++;
    }

    return res;
}

int main()
{
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14    2
    //   /  \   /  \  / \
    //17  23 27  3  8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> res = levelOrder(root);

    for (vector<int> level : res)
    {
        cout << "[";
        for (int i = 0; i < level.size(); i++)
        {
            cout << level[i];
            if (i < level.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }

    return 0;
}