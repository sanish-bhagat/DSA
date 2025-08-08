#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// utility that allocates a new Node with the given key
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

//! TC is O(n)
//! SC is O(n)

void flatten(Node *root)
{
    // using stack for LIFO
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        // push the curr -> right into stack if exists
        if (curr->right)
            st.push(curr->right);

        // push the left child nto st if exists
        if (curr->left)
            st.push(curr->left);

        // if stack is not empty then establish the right ptr to the top of the stack
        if (!st.empty())
            curr->right = st.top();

        // point the left child to NULL
        curr->left = NULL;
    }
}

void inorder(struct Node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
    /*    1
        /   \
       2     5
      / \     \
     3   4     6 */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
    flatten(root);
    cout << "The Inorder traversal after flattening binary tree ";
    inorder(root);
    return 0;
}
