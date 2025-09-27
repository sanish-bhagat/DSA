#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int kLargestRec(Node *root, int &cnt, int k)
{
    if (!root)
        return -1;

    int right = kLargestRec(root->right, cnt, k);

    if (right != -1)
        return right;

    cnt++;

    if (cnt == k)
        return root->data;

    int left = kLargestRec(root->left, cnt, k);
    return left;
}

//! TC is O(n)
//! SC is O(h)

int kthLargest(Node *root, int k)
{
    int cnt = 0;

    // traverse the BST in reverse inorder manner(decreasing element)
    return kLargestRec(root, cnt, k);
}

int main()
{

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int k = 3;

    cout << kthLargest(root, k) << endl;

    return 0;
}