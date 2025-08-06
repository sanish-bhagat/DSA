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

//! TC is O(n)
//! SC is O(n)

int sumOfLongRootToLeafPath(Node *root)
{
    int maxSum = 0;
    int maxLen = 0;

    // storing node with their sum and level
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {root->data, 1}});

    while (!q.empty())
    {
        int n = q.size();

        //traverse the curr level
        for (int i = 0; i < n; i++)
        {
            //pop the front of the queue
            auto front = q.front();
            q.pop();

            //get the node, sum and len of the curr node at the front
            Node *node = front.first;
            int sum = front.second.first;
            int len = front.second.second;

            //if leaf node then check and update the maxSum and maxLen
            if (!node->left && !node->right)
            {
                if (len > maxLen)
                {
                    maxSum = sum;
                    maxLen = len;
                }
                else if (len == maxLen && sum > maxSum)
                {
                    maxSum = sum;
                }
            }

            //push the left and right of the node, if exists, with the updated sum and len/level
            if (node->left)
                q.push({node->left, {sum + node->left->data, len + 1}});

            if (node->right)
                q.push({node->right, {sum + node->right->data, len + 1}});
        }
    }

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