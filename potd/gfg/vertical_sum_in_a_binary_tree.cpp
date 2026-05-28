#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
    // hashmap, {horizontal dist, sum}
    unordered_map<int, int> mp;

    void solve(Node *root, int dist, int &mn, int &mx)
    {
        // base case
        if (!root)
            return;

        // recurse for the left child with horizontal dist one lesser than the curr one
        solve(root->left, dist - 1, mn, mx);

        // visit the curr node and include it in the curr dist sum
        mp[dist] += root->data;

        // update the min and max dist
        mn = min(mn, dist);
        mx = max(mx, dist);

        // recurse for the right child with horizontal dist one more than the curr one
        solve(root->right, dist + 1, mn, mx);
    }

public:
    //! TC is O(n)
    //! SC is O(n)

    vector<int> verticalSum(Node *root)
    {
        // we make sure that the hashmap is empty
        mp.clear();

        // mn is for storing the min horizontal dist
        // mx is for storing the max horizontal dist
        int mn = 0, mx = 0;

        // recursively find the sum for every horizontal dist from the root node
        solve(root, 0, mn, mx);

        vector<int> res;

        // traverse through the map and build the res sum[]
        for (int i = mn; i <= mx; i++)
        {
            res.push_back(mp[i]);
        }

        return res;
    }
};

int main()
{

    // Create binary tree as shown in above figure
    //        1
    //      /  \  
  	//     2    3
    //    / \  / \
  	//   4   5 6  7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;

    vector<int> res = s.verticalSum(root);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}