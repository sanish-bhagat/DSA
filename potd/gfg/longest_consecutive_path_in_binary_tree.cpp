#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void dfs(Node *curr, Node *parentNode, int currLen, int &longestPath)
{
    // base case
    if (!curr)
        return;

    // valid path
    if (parentNode && curr->data == parentNode->data + 1)
        currLen++;

    // else, start a new path
    else
        currLen = 1;

    // recurse for left and right nodes
    dfs(curr->left, curr, currLen, longestPath);
    dfs(curr->right, curr, currLen, longestPath);

    // update the global max
    longestPath = max(longestPath, currLen);
}

//! TC is O(n)
//! SC is O(h)

int longestConsecutive(Node *root)
{
    if (!root)
        return -1;

    // keep track of the longest valid path possible
    int longestPath = 0;

    // start dfs from root while keeping track of parentNode
    dfs(root, NULL, 0, longestPath);

    return longestPath == 1 ? -1 : longestPath;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);

    cout << longestConsecutive(root);

    return 0;
}