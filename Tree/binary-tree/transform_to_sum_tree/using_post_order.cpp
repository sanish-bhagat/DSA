#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
public:
    int data;
    node *left;
    node *right;
};

void printInorder(node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int traversal(node *node)
{
    if (!node)
        return 0;

    // if the node is a leaf node, set the curr leaf node data to 0 and return the old node value
    if (node->left == NULL && node->right == NULL)
    {
        int curr = node->data;
        node->data = 0;
        return curr;
    }

    // upadte the curr node value to the sum of the old left subtree and old right subtree
    int temp = node->data;
    node->data = traversal(node->left) + traversal(node->right);
    return temp + node->data;
}

//! TC is O(n)
//! SC is O(h)

void toSumTree(node *node)
{
    int res = traversal(node->left) + traversal(node->right);

    node->data = res;
}

/* Driver code */
int main()
{
    node *root = NULL;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);

    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}