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
    vector<int> res;
    stack<Node *> st;

    while (true)
    {
        while (root)
        {
            st.push(root);
            st.push(root);
            root = root->left;
        }

        if (st.empty())
            return res;

        root = st.top();
        st.pop();

        if (!st.empty() && root == st.top())
            root = root->right;

        else
        {
            res.push_back(root->data);
            root = NULL;
        }
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