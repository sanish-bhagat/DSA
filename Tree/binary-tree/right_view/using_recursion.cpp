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

//! TC is O(n)
//! SC is O(h)

void rightViewRec(Node *root, int currLevel, int &maxLevel, vector<int> &res)
{
    if (root == NULL)
        return;

    // if the curr node is the first one in its level from the right then push it
    if (currLevel > maxLevel)
    {
        res.push_back(root->data);
        maxLevel = currLevel;
    }

    // first call for the right-subtree to get the postorder expression
    rightViewRec(root->right, currLevel + 1, maxLevel, res);
    rightViewRec(root->left, currLevel + 1, maxLevel, res);
}

vector<int> rightView(Node *root)
{
    vector<int> res;
    int maxLevel = -1;

    rightViewRec(root, 0, maxLevel, res);

    return res;
}

void printArray(vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{

    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //           / \   
    //          4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);

    printArray(result);

    return 0;
}