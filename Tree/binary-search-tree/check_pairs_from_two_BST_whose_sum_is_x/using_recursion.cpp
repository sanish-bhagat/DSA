#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

bool findVal(Node *root, int x) {
    if(!root)
        return false;

    if(root -> data == x)
        return true;

    else if(root -> data < x)
        return findVal(root -> right, x);

    else    
        return findVal(root -> left, x);
}

//! TC is O(n1 * n2)
//! SC is O(h1 + h2)

int countPairs(Node *root1, Node *root2, int x) {
    if(!root1)
        return 0;

    int cnt = 0;

    // traverse the 1st BST and
    // check the x - root1 -> data in the 2nd BST
    if(findVal(root2, x -  root1 -> data))
        cnt++;

    cnt += countPairs(root1 -> left, root2, x);
    cnt += countPairs(root1 -> right, root2, x);

    return cnt;
}

int main() {
    
    // BST1
    //    2
    //  /  \
    // 1   3
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    
    // BST2
    //    5
    //  /  \
    // 4   6
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);
    
    int x = 6;
    cout << countPairs(root1, root2, x);

    return 0;
}