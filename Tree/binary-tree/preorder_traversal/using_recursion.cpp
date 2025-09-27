#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void preOrderRec(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;

    //N
    res.push_back(root->data);
    //L
    preOrderRec(root->left, res);
    //R
    preOrderRec(root->right, res);
}

//! TC is O(n)
//! SC is O(h)

vector<int> preOrder(Node *root)
{
    vector<int> res;
    preOrderRec(root, res);

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preOrder(root);

    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}