#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            left = right = NULL;
        }
};

void inorder(Node *root) {
    if(root == NULL)
        return;

    inorder(root -> left);

    cout << root -> data << " ";

    inorder(root -> right);
}

// void mirror(Node *root) {
//     if(root == NULL)
//         return;

//     mirror(root ->left);
//     mirror(root -> right);

        ////swap the left and right child
//     Node *temp = root -> left;
//     root -> left = root -> right;
//     root -> right = temp;
// }

//! TC is O(n)
//! SC is O(h)

Node *mirror(Node *root) {
    if(root == NULL)
        return NULL;

    Node *leftMirror = mirror(root -> left);
    Node *rightMirror = mirror(root -> right);

    //swap the left and right child
    root -> left = rightMirror;
    root -> right = leftMirror;

    return root;
}

int main() {
    // Creating a sample binary tree
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder traversal of original tree: ";
    inorder(root);
    cout << endl;

    // Mirror the tree
    mirror(root);

    cout << "Inorder traversal of mirrored tree: ";
    inorder(root);
    cout << endl;

    return 0;
}