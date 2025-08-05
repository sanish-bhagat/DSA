#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

//! TCis O(n)
//! SC is O(n)

vector<int> leftView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> res;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();

            // push the first node of each level
            if (i == 0)
                res.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
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