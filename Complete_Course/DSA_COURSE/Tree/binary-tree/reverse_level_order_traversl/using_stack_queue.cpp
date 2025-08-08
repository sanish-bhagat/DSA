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

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    stack<Node *> st;
    queue<Node *> q;

    // push the root node into the queue
    q.push(root);

    while (!q.empty())
    {
        // push the fron node of the queue into the stack
        Node *curr = q.front();
        q.pop();
        st.push(curr);

        // if present, first push the right node then the left node into the q so that the reverse order remains maintained
        if (curr->right)
            q.push(curr->right);

        if (curr->left)
            q.push(curr->left);
    }

    // push the elements into the res from the stack
    while (!st.empty())
    {
        res.push_back(st.top()->data);
        st.pop();
    }

    return res;
}

int main()
{
    /*
        Tree Structure:
            1
           / \
          3   2
    */
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    vector<int> result = reverseLevelOrder(root);

    cout << "Reverse Level Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}