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
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<int> postOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> res;
    stack<Node *> st1;
    st1.push(root);
    stack<Node *> st2;

    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);

        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty())
    {
        res.push_back(st2.top()->data);
        st2.pop();
    }

    return res;
}

void printArray(const vector<int> &arr)
{
    for (int data : arr)
    {
        cout << data << " ";
    }
    cout << endl;
}

int main()
{

    // Representation of input binary tree:
    //           1
    //         /   \
    //        2     3
    //      /  \
    //     4    5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    printArray(result);

    return 0;
}