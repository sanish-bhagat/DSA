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

//! TC is O(n)
//! SC is O(n)

int minTime(Node *root, int target)
{
    // queue for level order traversal
    queue<Node *> q;
    q.push(root);

    // keep track of the parent of every node
    unordered_map<Node *, Node *> par;
    par[root] = NULL;

    Node *tar = NULL;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // curr node is target -> store it
        if (curr->data == target)
            tar = curr;

        // push the left and right child and store their parents
        if (curr->left)
        {
            par[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right)
        {
            par[curr->right] = curr;
            q.push(curr->right);
        }
    }

    // keep track of the visited nodes
    unordered_map<Node *, bool> vis;
    q.push(tar);
    vis[tar] = true;

    int ans = -1;

    while (!q.empty())
    {
        int size = q.size();

        // visit all the nodes in this level and burn them in one go
        while (size--)
        {
            // mark the curr node as visited
            Node *curr = q.front();
            vis[curr] = true;
            q.pop();

            // push the left child, right child and parent nodes in the queue for traversal
            if (curr->left && !vis[curr->left])
                q.push(curr->left);

            if (curr->right && !vis[curr->right])
                q.push(curr->right);

            if (par[curr] && !vis[par[curr]])
                q.push(par[curr]);
        }

        // increment the time taken to burn this level nodes by 1sec
        ans++;
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 2;

    cout << minTime(root, target) << endl;

    return 0;
}