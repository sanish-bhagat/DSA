#include <iostream>
#include <queue>
#include <vector>
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

int search(vector<int> &inorder, int val, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (inorder[i] == val)
            return i;
    }

    return -1;
}

Node *buildTreeRec(vector<int> &inorder, vector<int> &preorder, int &preIndex, int left, int right)
{
    if (left > right)
        return NULL;

    // get the node value from the preorder array
    int rootVal = preorder[preIndex];
    preIndex++;

    // create a node for this value
    Node *root = new Node(rootVal);

    // find the index of this node in inorder array
    int index = search(inorder, rootVal, left, right);

    // the left part from the index in inorder will be the left subtree and the right part from that index will be the right subtree
    // recursively build them
    root->left = buildTreeRec(inorder, preorder, preIndex, left, index - 1);
    root->right = buildTreeRec(inorder, preorder, preIndex, index + 1, right);

    return root;
}

//! TC is O(n * n)
//! SC is O(h)

Node *buildTree(vector<int> &inorder, vector<int> &preorder)
{
    // ptr to traverse the preorder array
    int preIndex = 0;
    Node *root = buildTreeRec(inorder, preorder, preIndex, 0, preorder.size() - 1);
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