// check if a binary tree contains duplicate subtrees of size 2 or more

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left, *right;
    Node(char x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

string dupSubRec(Node *root, unordered_map<string, int> &mpp)
{
    // if node is NULL return "N"
    if (!root)
        return "N";

    // for leaf node return the node's value converted into string
    if (root->left == NULL && root->right == NULL)
        return to_string(root->data);

    // traverse the left and right subtrees
    string left = dupSubRec(root->left, mpp);
    string right = dupSubRec(root->right, mpp);

    // Generalised the serialized form
    string curr = "";
    curr += to_string(root->data);
    curr += "*";
    curr += left;
    curr += "*";
    curr += right;

    // update the count in the map
    mpp[curr]++;

    return curr;
}

//! TC is O(n * n)
//! SC is O(n)

int dupSub(Node *root)
{
    // create a map to store the count of the subtrees
    unordered_map<string, int> mpp;

    // recursively traverse the tree and get the count of the subtrees
    dupSubRec(root, mpp);

    // check if any subtree appears twice, then return True
    for (auto it : mpp)
    {
        if (it.second > 1)
            return 1;
    }

    return 0;
}

int main()
{

    //         A
    //       /   \
    //      B     C
    //     / \     \
    //    D   E     B
    //           /   \
    //          D     E
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left = new Node('D');

    if (dupSub(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}