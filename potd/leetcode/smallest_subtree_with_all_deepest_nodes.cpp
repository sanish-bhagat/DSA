#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        // base case: no node present -> return {LCA node, depth}
        if (!root)
            return {NULL, 0};

        // recurse for left and right subtree
        pair<TreeNode *, int> left = dfs(root->left);
        pair<TreeNode *, int> right = dfs(root->right);

        // left subtree is deepest than right subtree
        if (left.second > right.second)
            return {left.first, left.second + 1};

        // right subtree is deepest than left subtree
        else if (right.second > left.second)
            return {right.first, right.second + 1};

        // both subtrees have same depth -> return root node
        else
            return {root, left.second + 1};
    }

public:
    //! TC is O(n)
    //! SC is O(h)

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        // find the LCA of the deepest nodes
        return dfs(root).first;
    }
};

int main()
{
    /*
            1
           / \
          2   3
             / \
            5   6

        Deepest nodes = 5,6
        Answer = 3
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    TreeNode *ans = sol.subtreeWithAllDeepest(root);

    cout << "Root of smallest subtree containing all deepest nodes: "
         << ans->val << endl;

    return 0;
}