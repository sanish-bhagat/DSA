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

void storeNodes(Node *root, unordered_set<int> &allNodes, unordered_set<int> &leafNodes)
{
    if (!root)
        return;

    allNodes.insert(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        leafNodes.insert(root->data);
        return;
    }

    storeNodes(root->left, allNodes, leafNodes);
    storeNodes(root->right, allNodes, leafNodes);
}

//! TC is O(n)
//! SC is O(n)

bool isDeadEnd(Node *root)
{
    unordered_set<int> allNodes, leafNodes;

    // insert 0 for node having value 1
    allNodes.insert(0);

    // recursively store all nodes and leaf nodes into different set
    storeNodes(root, allNodes, leafNodes);

    // for value present in leaf node check if any one of the value
    //  have both of its immediate predecessor(val - 1) and successor(val + 1) present then its a dead end
    for (int val : leafNodes)
    {
        if (allNodes.count(val - 1) && allNodes.count(val + 1))
            return true;
    }

    return false;
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