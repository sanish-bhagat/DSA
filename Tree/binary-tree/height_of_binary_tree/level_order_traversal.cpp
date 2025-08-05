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

//! TC is O(n)
//! SC is O(n)

int height(Node *root)
{
    // base case
    if (root == NULL)
        return -1;

    int depth = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
        depth++;
    }

    return depth - 1;
}

int main()
{

    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << height(root);

    return 0;
}