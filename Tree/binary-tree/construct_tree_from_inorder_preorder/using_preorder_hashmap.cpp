#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
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

// Print tree as level order
void printLevelOrder(Node *root)
{
    if (root == nullptr)
    {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0)
    {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr)
        {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

Node *buildTreeRec(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &mpp, int &preIndex, int left, int right)
{
    if (left > right)
        return NULL;

    int rootVal = preorder[preIndex];
    preIndex++;

    Node *root = new Node(rootVal);

    // get the index from the map
    int index = mpp[rootVal];

    root->left = buildTreeRec(inorder, preorder, mpp, preIndex, left, index - 1);
    root->right = buildTreeRec(inorder, preorder, mpp, preIndex, index + 1, right);

    return root;
}

//! TC is O(n)
//! SC is O(n)

Node *buildTree(vector<int> &inorder, vector<int> &preorder)
{
    int preIndex = 0;
    unordered_map<int, int> mpp;

    // map the values of the array to their indices
    for (int i = 0; i < inorder.size(); i++)
        mpp[inorder[i]] = i;

    Node *root = buildTreeRec(inorder, preorder, mpp, preIndex, 0, preorder.size() - 1);

    return root;
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}