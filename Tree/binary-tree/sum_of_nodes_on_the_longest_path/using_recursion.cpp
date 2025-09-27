#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void sumOfLongRootToLeafPathRec(Node *root, int sum, int len, int &maxSum, int &maxLen)
{
    //if node is null, check the conditions and update the values
    if (!root)
    {
        if (len > maxLen)
        {
            maxSum = sum;
            maxLen = len;
        }
        else if (len == maxLen && sum > maxSum)
            maxSum = sum;

        return;
    }

    //recursive calls for left and right subtrees for calculating sum
    sumOfLongRootToLeafPathRec(root->left, sum + root->data, len + 1, maxSum, maxLen);
    sumOfLongRootToLeafPathRec(root->right, sum + root->data, len + 1, maxSum, maxLen);
}

//! TC is O(n)
//! SC is O(h)

int sumOfLongRootToLeafPath(Node *root)
{
    if (!root)
        return 0;

    int maxSum = INT_MIN;
    int maxLen = 0;

    //recursively traverse and gt the maxSum of the longest path
    sumOfLongRootToLeafPathRec(root, 0, 0, maxSum, maxLen);

    return maxSum;
}

int main()
{

    // binary tree formation
    //        4
    //       / \ 
    //      2   5
    //     / \ 
    //    1  3
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << sumOfLongRootToLeafPath(root);

    return 0;
}