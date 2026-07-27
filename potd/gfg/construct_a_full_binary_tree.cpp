#include <bits/stdc++.h>
using namespace std;

// Definition of Node
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> &pre, vector<int> &preMirror, int &preIndex, int left,
                int right, unordered_map<int, int> &mp, int n)
{
    // Base case
    if (preIndex >= n || left > right)
        return NULL;

    // Create current node
    Node *root = new Node(pre[preIndex++]);

    // If leaf node
    if (left == right)
        return root;

    // Find next preorder element index in preMirror
    int mirrorIndex = mp[pre[preIndex]];

    // Construct left and right subtree
    if (mirrorIndex >= left && mirrorIndex <= right)
    {
        // Construct left subtree
        root->left = buildTree(pre, preMirror, preIndex, mirrorIndex, right, mp, n);

        // Construct right subtree
        root->right =
            buildTree(pre, preMirror, preIndex, left + 1, mirrorIndex - 1, mp, n);
    }

    return root;
}

//! TC is O(n)
//! SC is O(n)

Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror)
{
    int n = pre.size();

    // Store indices of mirror preorder traversal
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[preMirror[i]] = i;
    }

    int preIndex = 0;

    return buildTree(pre, preMirror, preIndex, 0, n - 1, mp, n);
}

// Inorder traversal
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> preMirror = {1, 3, 7, 6, 2, 5, 4};

    Node *root = constructBinaryTree(pre, preMirror);

    inorder(root);

    return 0;
}