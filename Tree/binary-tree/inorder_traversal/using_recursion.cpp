#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = right = NULL;
        }
};

void inOrderRec(Node *root, vector<int> &res) {
    if(root == NULL)
        return;

    //L
    inOrderRec(root -> left, res);
    //N
    res.push_back(root -> data);
    //R
    inOrderRec(root -> right, res);
}

//! TC is O(n)
//! SC is O(h)

vector<int> inOrder(Node *root) {
    if(root == NULL)
        return {};

    vector<int> res;
    inOrderRec(root, res);

    return res;
}

int main() {
    
    // Constructed binary tree is
    //          1
    //        /   \
    //      2      3
    //    /  \
    //  4     5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}