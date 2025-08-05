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

//! TC is O(h)
//! SC is O(h)

Node *LCA(Node *root, Node *n1, Node *n2) {
    if(!root)
        return NULL;

    // if node's value is greater than both n1 and n2 then pur LCA is in the left side of the node
    if(root -> data > n1 -> data && root -> data > n2 -> data)
        return LCA(root -> left, n1 , n2);
        
    // if node's value is smaller than both n1 and n2 then pur LCA is in the right side of the node
    if(root -> data < n1 -> data && root -> data < n2 -> data)
        return LCA(root -> right, n1, n2);

    // if node's value lies between n1 and n2 then its our LCA(n1 <= n <= n2)
    return root;
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