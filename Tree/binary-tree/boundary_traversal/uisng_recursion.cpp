#include <iostream>
#include <vector>
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
        left = right = nullptr;
    }
};

bool isLeaf(Node *root)
{
    return ((root->left == NULL) && (root->right == NULL));
}

void leftBoundary(Node *root, vector<int> &res)
{
    if (!root || isLeaf(root))
        return;

    res.push_back(root->data);

    if (root->left)
        leftBoundary(root->left, res);

    else if (root->right)
        leftBoundary(root->right, res);
}

void rightBoundary(Node *root, vector<int> &res)
{
    if (!root || isLeaf(root))
        return;

    if (root->right)
        rightBoundary(root->right, res);

    else if (root->left)
        rightBoundary(root->left, res);

    res.push_back(root->data);
}

void leafNodes(Node *root, vector<int> &res)
{
    if (!root)
        return;

    if (isLeaf(root))
        res.push_back(root->data);

    leafNodes(root->left, res);
    leafNodes(root->right, res);
}

//! TC is O(n)
//! SC is O(h)

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;

    if (!root)
        return res;

    // push the root node
    if (!isLeaf(root))
        res.push_back(root->data);

    // collect the left boundary nodes excluding leaf nodes
    leftBoundary(root->left, res);

    // collect all the leaf nodes  of the tree
    leafNodes(root, res);

    // collect the right boundary nodes in the reverse order excluding leaf nodes
    rightBoundary(root->right, res);

    return res;
}

int main()
{

    // Hardcoded Binary tree
    //        20
    //       /  \
    //      8    22
    //     / \     \
    //    4   12    25
    //       /  \
    //      10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}