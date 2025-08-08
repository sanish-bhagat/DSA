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

    // store the curr value of the node(i.e the old value)
    int old_value = node->data;

    // recursive call for left and right subtree
    node->data = traversal(node->left) + traversal(node->right);

    return node->data + old_value;
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