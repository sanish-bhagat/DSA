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

void postorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);

    cout << root->data << " ";
}

void inorder(Node *root, vector<int> &inorderArray)
{
    if (!root)
        return;

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

void postorder(Node *root, vector<int> &inorderArray, int &index)
{
    if (!root)
        return;

    postorder(root->left, inorderArray, index);
    postorder(root->right, inorderArray, index);

    root->data = inorderArray[index++];
}

//! TC is O(n)
//! SC is O(n)

void convertBSTtoMaxHeap(Node *root)
{
    // find the inorder of the BST
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int index = 0;

    // using the inorder[] and the postorder traversal build the max heap
    postorder(root, inorderArray, index);
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

    convertBSTtoMaxHeap(root);
    postorderPrint(root);

    return 0;
}