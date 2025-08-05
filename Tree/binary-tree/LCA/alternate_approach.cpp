#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

bool checkIfPresent(Node *root, int k)
{
    if (!root)
        return false;

    // check if key is present in the tree or not, if present then return true, else false
    if (root->data == k || checkIfPresent(root->left, k) || checkIfPresent(root->right, k))
        return true;

    return false;
}

Node *findLca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLca = findLca(root->left, n1, n2);
    Node *rightLca = findLca(root->right, n1, n2);

    if (leftLca == NULL)
        return rightLca;

    else if (rightLca == NULL)
        return leftLca;

    else
        return root;
}

//! TC is O(n)
//! SC is O(n)

Node *lca(Node *root, int n1, int n2)
{
    // if both keys are present in the tree then only find the lca, else if any one of them are absent then return NULL
    if (checkIfPresent(root, n1) && checkIfPresent(root, n2))
        return findLca(root, n1, n2);

    return NULL;
}

int main()
{

    // construct the binary tree
    //			   1
    //           /   \
    //          2     3
    //         / \   / \
    //        4  5  6   7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *ans = lca(root, 4, 5);
    if (ans == nullptr)
        cout << "No common ancestor found";
    else
        cout << ans->data;
    return 0;
}