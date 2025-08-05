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

void preorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorder(Node *root, vector<int> &inorderArray)
{
    if (!root)
        return;

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

void preorder(Node *root, vector<int> &inorderArray, int &index)
{
    if (!root)
        return;

    root->data = inorderArray[index++];

    preorder(root->left, inorderArray, index);
    preorder(root->right, inorderArray, index);
}

//! TC is O(n)
//! SC is O(n)

void convertBSTtoMinHeap(Node *root)
{
    if (!root)
        return;

    // find the inorder of the BST
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int index = 0;

    // using the inorder[] and preorder traversal update the BST
    preorder(root, inorderArray, index);
}

int main()
{

    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTtoMinHeap(root);
    preorderPrint(root);

    return 0;
}