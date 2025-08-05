#include <bits/stdc++.h>
using namespace std;

// tree node
struct Node
{
    int data;
    Node *left, *right;
};

// returns a new tree Node
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool checkUtil(Node *root, int level, int &leafLevel)
{
    if (root == NULL)
        return true;

    // if vurr node is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        // if its the first leafnode encountered then update leafLevel to level
        if (leafLevel == 0)
        {
            leafLevel = level;
            return true;
        }

        // If this is not first leaf node, compare
        // its level with first leaf's level
        return (leafLevel == level);
    }

    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

//! TC is O(n)
//! SC is O(h)

bool check(Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, leafLevel);
}

int main()
{
    // Let us create tree shown in third example
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    // getchar();
    return 0;
}