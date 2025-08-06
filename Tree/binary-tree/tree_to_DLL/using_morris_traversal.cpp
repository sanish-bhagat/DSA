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

Node *morrisTraversal(Node *root)
{
    // head and tail ptrs for DLL
    Node *head = NULL, *tail = NULL;

    // ptr to traverse the tree
    Node *curr = root;

    while (curr)
    {
        // if leftTree not exists
        if (curr->left == NULL)
        {
            if (head == NULL)
            {
                head = tail = curr; // point the first node of the DLL as head
            }

            // append the node to DLL
            else
            {
                tail->right = curr;
                curr->left = tail;
                tail = curr;
            }

            curr = curr->right;
        }

        // left subtree exists then find the inorder predecessor
        else
        {
            Node *pred = curr->left;

            while (pred->right && pred->right != curr)
                pred = pred->right;

            // create a link between pred and curr and then move to its left
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }

            // we have traversed the left subtree now we can append the node to the DLL and move right
            else
            {
                tail->right = curr;
                curr->left = tail;
                tail = curr;
                curr = curr->right;
            }
        }
    }

    // return the first node as the head of the DLL
    return head;
}

//! TC is O(n)
//! SC is O(1)

Node *bToDLL(Node *root)
{
    if (!root)
        return root;

    return morrisTraversal(root);
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