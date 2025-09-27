#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
      	right = nullptr;
    }
};

class BSTInfo{
    public:
        int min;
        int max;
        int mxSz;

        BSTInfo(int mini, int maxi, int sz) {
            min = mini;
            max = maxi;
            mxSz = sz;
        }
};

BSTInfo largestBstBT(Node *root) {
    if(!root)
        return BSTInfo(INT_MAX, INT_MIN, 0);

    BSTInfo left = largestBstBT(root -> left);
    BSTInfo right = largestBstBT(root -> right);

    if(left.max < root -> data && right.min > root -> data) 
        return BSTInfo(min(left.min, root -> data), max(root-> data, right.max), 1 + left.mxSz + right.mxSz);

    return BSTInfo(INT_MIN, INT_MAX, max(left.mxSz, right.mxSz));
}

int largestBst(Node *root) {
    return largestBstBT(root).mxSz;
}

int main() {
  
	// Constructed binary tree looks like this:
    //         50
    //       /    \
    //     75      45
    //    /
    //  40

    Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);

    cout << largestBst(root) << endl;
    return 0;
}