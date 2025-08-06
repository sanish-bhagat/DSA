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

void fixPrev(Node *root, Node *&prev)
{
    if (!root)
        return;

    // recur call for the left child
    fixPrev(root->left, prev);

    // fix the left ptr
    root->left = prev;
    prev = root;

    // recur call for the right child
    fixPrev(root->right, prev);
}

Node *fixNext(Node *root)
{
    if (!root)
        return NULL;

    Node *prev = NULL;

    // get the rightmost node i.e the last node of the DLL
    while (root && root->right)
        root = root->right;

    // traverse the DLL using the left ptr and fix the right ptr
    while (root)
    {
        root->right = prev;
        prev = root;
        root = root->left;
    }

    // return the head of the DLL(root will be pointing to NULL after the traversal and prev to the first node)
    return prev;
}

//! TC is O(n)
//! SC is O(n)

Node *bToDLL(Node *root)
{
    if (!root)
        return root;

    Node *prev = NULL;

    // fix the left ptrs during inorder traversal
    fixPrev(root, prev);

    // fix the right ptrs
    return fixNext(root);
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