#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool checkIfPresent(Node *root, Node *n1) {
    if(!root)
        return false;

    if(root -> data == n1 -> data || checkIfPresent(root -> left, n1) || checkIfPresent(root -> right, n1))
        return true;

    return false;
}

Node *findLca(Node *root, Node *n1, Node *n2) {
    if(!root)
        return NULL;

    if(root -> data == n1 -> data || root -> data == n2 -> data)
        return root;

    Node *leftLca = findLca(root -> left, n1, n2);
    Node *rightLca = findLca(root -> right, n1, n2);

    if(leftLca == NULL)
        return rightLca;

    else if(rightLca == NULL)
        return leftLca;

    else
        return root;
}

Node *LCA(Node *root, Node *n1, Node *n2) {
    if(checkIfPresent(root, n1) && checkIfPresent(root, n2))
        return findLca(root, n1, n2);

    return NULL;
}

int main() {
  	
  	// Representation of input BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14  
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* n1 = root->left->left; // Node 4
    Node* n2 = root->left->right->right; // Node 14

    Node* res = LCA(root, n1, n2);
    cout << res->data << endl;

    return 0;
}