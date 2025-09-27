#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
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

vector<int> preOrder(Node *root)
{
    vector<int> res;

    stack<Node *> st;
    Node *curr = root;

    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            res.push_back(curr->data);

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        if (!st.empty())
        {
            curr = st.top();
            st.pop();
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

    vector<int> preorder = preOrder(root);

    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}