#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! TC is O(n)
//! SC is O(n)

int maxLevelSum(TreeNode *root)
{
    // BFS traversal
    queue<TreeNode *> pq;

    pq.push(root);

    int ans = 1, lvl = 1;
    long long maxSum = LLONG_MIN;

    // traverse the tree in BFS manner
    while (!pq.empty())
    {
        // no. of nodes in curr level
        int size = pq.size();
        long long currSum = 0;

        // find the sum of the nodes in the curr level
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = pq.front();
            pq.pop();

            currSum += node->val;

            // push the children, if they exists
            if (node->left)
                pq.push(node->left);

            if (node->right)
                pq.push(node->right);
        }

        // update maxSum and ans level, if we found one
        if (currSum > maxSum)
        {
            maxSum = currSum;
            ans = lvl;
        }

        // increment the level for the next children
        lvl++;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(-100);
    root->left = new TreeNode(-200);
    root->right = new TreeNode(-300);
    root->left->left = new TreeNode(-20);
    root->left->right = new TreeNode(-5);
    root->right->left = new TreeNode(-10);

    cout << "Level with maximum sum: " << maxLevelSum(root) << endl;

    return 0;
}