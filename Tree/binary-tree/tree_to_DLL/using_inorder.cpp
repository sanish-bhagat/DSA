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

void inorderTraversal(Node *root)
{
    // if left subtree exist find the inorder predecessor
    if (root->left)
    {
        Node *pred = root->left;

        while (pred->right)
            pred = pred->right;

        inorderTraversal(root->left);

        // link the root node and predecessor
        pred->right = root;
        root->left = pred; // pred comes before the root node so we s=will link the root's left ptr to pred
    }

    // if right tree exist find the inorder successor
    if (root->right)
    {
        Node *succ = root->right;

        while (succ->left)
            succ = succ->left;

        inorderTraversal(root->right);

        // link the root node and successor
        root->right = succ; // succ comes after the root node so we will link the root's right ptr to succ
        succ->left = root;
    }
}

//! TC is O(n)
//! SC is O(h)

Node *bToDLL(Node *root)
{
    if (!root)
        return root;

    // find the head of the DLL(leftmost node of the tree)
    Node *head = root;
    while (head->left)
        head = head->left;

    inorderTraversal(root);

    return head;
}

void printList(Node *head)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{

    // Create a hard coded binary tree
    //          10
    //         /  \
    //       12    15
    //      / \    /
    //     25 30  36
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = bToDLL(root);

    printList(head);

    return 0;
}