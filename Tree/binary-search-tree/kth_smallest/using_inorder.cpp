#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int lCount;
    Node *left;
    Node *right;
    Node(int x, int l)
    {
        data = x;
        lCount = l;
        left = nullptr;
        right = nullptr;
    }
};

int kSmallestRec(Node *root, int &cnt, int k)
{
    if (!root)
        return -1;

    int left = kSmallestRec(root->left, cnt, k);

    if (left != -1)
        return left;

    cnt++;

    if (cnt == k)
        return root->data;

    int right = kSmallestRec(root->right, cnt, k);
    return right;
}

//! TC is O(k)
//! SC is O(h)

int kthSmallest(Node *root, int k)
{
    int cnt = 0;
    // traverse the BST in inorder manner while maintaining the cnt of nodes traversed
    return kSmallestRec(root, cnt, k);
}

int main()
{

    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node *root = new Node(20, 5);
    root->left = new Node(8, 1);
    root->right = new Node(22, 0);
    root->left->left = new Node(4, 0);
    root->left->right = new Node(12, 1);
    root->left->right->left = new Node(10, 0);
    root->left->right->right = new Node(14, 0);
    int k = 3;

    cout << kthSmallest(root, k) << endl;
    return 0;
}