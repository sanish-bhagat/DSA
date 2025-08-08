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

void printPathsUtil(Node *root, int sum, int currSum, vector<int> &path, vector<vector<int>> &ans)
{
    if (!root)
        return;

    // add the curr node's value to the running sum and push the node's value into the path
    currSum += root->data;
    path.push_back(root->data);

    // if path sum matches the target then save the path
    if (currSum == sum)
        ans.push_back(path);

    if (root->left)
        printPathsUtil(root->left, sum, currSum, path, ans);

    if (root->right)
        printPathsUtil(root->right, sum, currSum, path, ans);

    // while bacltracking pop the element from the back to explore other paths
    path.pop_back();
}

//! TC is O(n * h)
//! SC is O(h), while backtracking all the elements are popped from the path and it becomes empty, so space is used for only recursive calls

vector<vector<int>> printPaths(Node *root, int sum)
{
    vector<int> path;
    vector<vector<int>> ans;

    // currSum is passed as 0 at the starting
    printPathsUtil(root, sum, 0, path, ans);

    return ans;
}

void print2DArray(vector<vector<int>> &result)
{
    for (auto &path : result)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{

    // Representation of given Binary Tree
    //        1
    //       / \
    //      20  3
    //         / \
    //        4   15
    //       /
    //      6
    Node *root = new Node(1);
    root->left = new Node(20);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(15);
    root->right->left->left = new Node(6);

    int sum = 8;

    vector<vector<int>> result = printPaths(root, sum);

    print2DArray(result);

    return 0;
}