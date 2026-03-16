#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int countRec(Node *node, int k, int sum, unordered_map<int, int> &prefSums)
{
    // base case
    if (!node)
        return 0;

    int pathCount = 0;

    // include the curr node in the curr path sum
    sum += node->data;

    // path sum == target -> valid path
    if (sum == k)
        pathCount++;

    // tells the no. of paths with sum == k till curr node
    pathCount += prefSums[sum - k];

    // include the curr sum in the hashmap
    prefSums[sum]++;

    // recursively move to the left and right nodes
    pathCount += countRec(node->left, k, sum, prefSums);
    pathCount += countRec(node->right, k, sum, prefSums);

    // exclude the curr sum from the hashmap
    prefSums[sum]--;

    return pathCount;
}

//! TC is O(n)
//! SC is O(n)

int countAllPaths(Node *root, int k)
{
    // store the running prefixSum for every path
    unordered_map<int, int> prefSums;

    // recursively find the total path count
    return countRec(root, k, 0, prefSums);
}

int main()
{

    // Create a sample tree:
    //        8
    //      /  \
    //     4    5
    //    / \    \
    //   3   2    2
    //  / \   \
    // 3  -2   1

    Node *root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7;

    cout << countAllPaths(root, k) << endl;
    return 0;
}