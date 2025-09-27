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
//! SC is O(h)

vector<int> inOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> res;
    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        //reach the left-most node of the curr node
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        //when curr is NULL pop the top node and push its data into res
        curr = st.top();
        st.pop();

        res.push_back(curr->data);

        //visited node and its left-subtree now its right-subtree's turn
        curr = curr->right;
    }

    return res;
}

int main()
{

    // Constructed binary tree is
    //          1
    //        /   \
    //      2      3
    //    /  \
    //  4     5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}