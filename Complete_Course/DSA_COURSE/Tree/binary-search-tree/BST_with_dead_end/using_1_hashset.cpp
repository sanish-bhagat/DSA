#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void storeNodes(Node *root, unordered_set<int> &allNodes)
{
    if (!root)
        return;

    allNodes.insert(root->data);

    storeNodes(root->left, allNodes);
    storeNodes(root->right, allNodes);
}

bool isDeadEndRec(Node *root, unordered_set<int> allNodes)
{
    if (!root)
        return false;

    // if its a leaf node and its immediate predecessor and successor both are present then
    //  its a dead end
    if (root->left == NULL && root->right == NULL)
    {
        int val = root->data;

        if (allNodes.count(val - 1) && allNodes.count(val + 1))
            return true;
    }

    return isDeadEndRec(root->left, allNodes) || isDeadEndRec(root->right, allNodes);
}

//! TC is O(n)
//! SC is O(n)

bool isDeadEnd(Node *root)
{
    unordered_set<int> allNodes;

    allNodes.insert(0);

    // store all the node values of the bst into the set
    storeNodes(root, allNodes);

    // now check for leaf node if its immediate predecessor and successor both are present in the set then
    // there is a dead end in the BST
    return isDeadEndRec(root, allNodes);
}

int main()
{

    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    if (isDeadEnd(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}