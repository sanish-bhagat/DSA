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

Node *buildTreeRec(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mpp, int &pIndex, int left, int right)
{
    if (left > right)
        return NULL;

    int rootVal = postorder[pIndex];
    pIndex--;

    Node *root = new Node(rootVal);

    //get the index from the map
    int index = mpp[rootVal];

    root->right = buildTreeRec(inorder, postorder, mpp, pIndex, index + 1, right);
    root->left = buildTreeRec(inorder, postorder, mpp, pIndex, left, index - 1);

    return root;
}

//! TC is O(n)
///! SC is O(n)

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = postorder.size();
    int pIndex = n - 1;

    unordered_map<int, int> mpp;

    //map the values of the inorder array to their indices
    for (int i = 0; i < n; i++)
        mpp[inorder[i]] = i;

    return buildTreeRec(inorder, postorder, mpp, pIndex, 0, n - 1);
}

int main()
{
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *root = buildTree(inorder, postorder);
    print(root);
    return 0;
}