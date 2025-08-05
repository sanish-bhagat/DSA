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
        left = right = nullptr;
    }
};

void print(Node *curr)
{
    if (curr == nullptr)
        return;
    cout << curr->data << " ";
    print(curr->left);
    print(curr->right);
}

int search(vector<int> &inorder, int val, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (inorder[i] == val)
            return i;
    }

    return -1;
}

Node *buildTreeRec(vector<int> &inorder, vector<int> &postorder, int &pIndex, int left, int right)
{
    if (left > right)
        return NULL;

    // get the node value
    int rootVal = postorder[pIndex];
    pIndex--;

    // create the node
    Node *root = new Node(rootVal);

    // search in inorder array to get the idea of the left and right subtree of the curr node
    int index = search(inorder, rootVal, left, right);

    // recursive call for the right subtree first and then the left subtree
    root->right = buildTreeRec(inorder, postorder, pIndex, index + 1, right);
    root->left = buildTreeRec(inorder, postorder, pIndex, left, index - 1);

    return root;
}

//! TC is O(n * n)
//! SC is O(h)

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = postorder.size();

    // to traverse the postorder array
    int pIndex = n - 1;

    return buildTreeRec(inorder, postorder, pIndex, 0, n - 1);
}

int main()
{
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *root = buildTree(inorder, postorder);
    print(root);
    return 0;
}