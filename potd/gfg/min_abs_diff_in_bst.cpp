#include <bits/stdc++.h>
using namespace std;

// class for tree node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// inorder traversal while keeping track of previous node
void inorder(Node *curr, Node *&prev, int &ans)
{
    // base case
    if (curr == nullptr)
        return;

    // go to left subtree
    inorder(curr->left, prev, ans);

    // process current node
    if (prev != nullptr)
        ans = min(ans, curr->data - prev->data);

    prev = curr; // update previous node

    // go to right subtree
    inorder(curr->right, prev, ans);
}

int absDiff(Node *root)
{
    Node *prev = nullptr;
    int ans = INT_MAX;

    // inorder traversal (gives sorted order)
    inorder(root, prev, ans);

    return ans;
}

// Driver code
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << absDiff(root);

    return 0;
}