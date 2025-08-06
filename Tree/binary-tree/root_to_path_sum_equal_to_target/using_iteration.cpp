#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(h)

bool hasPathSum(Node *root, int target)
{
    if (!root)
        return 0;

    // stack to store the nodes
    stack<Node *> st;
    st.push(root);

    // stack to store the sum of the nodes
    stack<int> sums;
    sums.push(root->data);

    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();

        int sum = sums.top();
        sums.pop();

        // if the sum == target and the curr node is a leaf node then true
        if (sum == target && node->left == NULL && node->right == NULL)
            return 1;

        // push the left and right nodes into the node stack and sum + left child or sum + right child into the sum stack
        if (node->left)
        {
            st.push(node->left);
            sums.push(sum + node->left->data);
        }

        if (node->right)
        {
            st.push(node->right);
            sums.push(sum + node->right->data);
        }
    }

    return 0;
}

int main()
{

    int sum = 21;

    // Constructed binary tree is
    //         10
    //       /    \
    //      8      2
    //     / \    /
    //    3   5  2

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if (hasPathSum(root, sum))
    {
        cout << "True" << endl;
    }
    else
        cout << "False";

    return 0;
}