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
//! SC is O(h)

int kthLargest(Node *root, int k)
{
    Node *curr = root;
    stack<Node *> st;
    int cnt = 0;

    // traverse the BST in reverse inorder manner
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->right;
        }

        curr = st.top();
        st.pop();

        cnt++;

        if (cnt == k)
            return curr->data;

        curr = curr->left;
    }

    return -1;
}

int main()
{

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int k = 3;

    cout << kthLargest(root, k) << endl;

    return 0;
}