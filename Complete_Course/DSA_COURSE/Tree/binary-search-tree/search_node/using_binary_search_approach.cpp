#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int item)
    {
        key = item;
        left = right = NULL;
    }
};

//! TC is O(h)
//! SC is O(h)

bool search(Node *root, int x)
{
    // base case
    if (root == NULL)
        return false;

    // if value found retun true
    if (root->key == x)
        return true;

    // if curr value is small then search in right subtree(property of BST -> left subtree contains small element and
    // right subtree contains large element than root)
    if (root->key < x)
        return search(root->right, x);

    // if curr value is large search in the left subtree
    return search(root->left, x);
}

int main()
{

    // Creating a hard coded tree for keeping
    // the length of the code small. We need
    // to make sure that BST properties are
    // maintained if we try some other cases.
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    (search(root, 19)) ? cout << "Found\n" : cout << "Not Found\n";

    (search(root, 80)) ? cout << "Found\n" : cout << "Not Found\n";

    return 0;
}