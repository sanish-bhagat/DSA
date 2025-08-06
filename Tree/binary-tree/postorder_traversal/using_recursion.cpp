#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void postOrderRec(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;

    postOrderRec(root->left, res);
    postOrderRec(root->right, res);

    res.push_back(root->data);
}

//! TC is O(n)
//! SC is O(h)

vector<int> postOrder(Node *root)
{
    vector<int> res;

    postOrderRec(root, res);

    return res;
}

void printArray(const vector<int> &arr)
{
    for (int data : arr)
    {
        cout << data << " ";
    }
    cout << endl;
}

int main()
{

    // Representation of input binary tree:
    //           1
    //         /   \
    //        2     3
    //      /  \
    //     4    5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    printArray(result);

    return 0;
}