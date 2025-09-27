#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *root, int l, int h, int &cnt)
{
    if (!root)
        return;

    // check left tree if curr node data is large than the lower limit
    if (root->data > l)
        inorder(root->left, l, h, cnt);

    // node falls in the range
    if (root->data >= l && root->data <= h)
        cnt++;

    // check right tree if curr node data is small than the upper limit
    if (root->data < h)
        inorder(root->right, l, h, cnt);
}

//! TC is O(n)
//! SC is O(h)

int getCount(Node *root, int l, int h)
{
    int cnt = 0;

    inorder(root, l, h, cnt);

    return cnt;
}

int main()
{

    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50
    //     /   /  \    
    //    1   40  100
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;

    cout << getCount(root, l, h) << endl;

    return 0;
}