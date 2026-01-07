#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    long long totalSum = 0;
    long long maxProd = 0;
    long long MOD = 1e9 + 7;

    // function to compute the total sum of the given binary tree
    long long dfsSum(TreeNode *root)
    {
        if (!root)
            return 0;

        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }

    long long dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        // subsum for left subtree
        long long left = dfs(root->left);

        // subsum of right subtree
        long long right = dfs(root->right);

        // curr subtree subsum
        long long subSum = root->val + left + right;

        // product of the curr splitted subtrees
        long long prod = subSum * (totalSum - subSum);

        // maximise the product
        maxProd = max(maxProd, prod);

        // return the curr subtree subsum for other dfs
        return subSum;
    }

    //! TC is O(n)
    //! SC is O(n)

    int maxProductSplit(TreeNode *root)
    {
        // total sum of the binary tree
        totalSum = dfsSum(root);

        // calculate subsum of every subtree and maximize the product
        dfs(root);

        return maxProd % MOD;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution sol;
    cout << sol.maxProductSplit(root) << endl; // Output: 9

    return 0;
}