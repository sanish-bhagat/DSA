#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};

    // one stack is used to traverse the curr level and other is used to store the nodes of the next level
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);

    vector<int> res;

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();

            res.push_back(curr->data);

            // first go to left subtree then to the right subtree
            if (curr->left)
                s2.push(curr->left);

            if (curr->right)
                s2.push(curr->right);
        }

        while (!s2.empty())
        {
            Node *curr = s2.top();
            s2.pop();

            res.push_back(curr->data);

            // first go to right subtree then to the left subtree
            if (curr->right)
                s1.push(curr->right);

            if (curr->left)
                s1.push(curr->left);
        }
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

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    vector<int> ans = zigZagTraversal(root);
    printList(ans);

    return 0;
}