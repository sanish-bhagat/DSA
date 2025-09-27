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
//! SC is O(1)

bool search(Node *root, int x)
{
    Node *curr = root;

    // traverse the BST
    while (curr)
    {
        // if value found return true
        if (curr->key == x)
            return true;

        // if curr value is grater than the target, serach in the right subtree
        else if (curr->key < x)
            curr = curr->right;

        // if curr value is smaller than the target, search in the left subtree
        else
            curr = curr->left;
    }

    // if curr becomes NULL, means target is not present in BST, return false
    return false;
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