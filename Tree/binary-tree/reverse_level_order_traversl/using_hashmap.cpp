#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//! TC is O(n)
//! SC is O(n)

void addNodeToMap(Node *root, int level, unordered_map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;

    // map the level with the list of data at that level
    mp[level].push_back(root->data);

    // recursive calls
    addNodeToMap(root->left, level + 1, mp);
    addNodeToMap(root->right, level + 1, mp);
}

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    unordered_map<int, vector<int>> mp;

    addNodeToMap(root, 0, mp);

    // traverse from the last height/level of the tre
    for (int level = mp.size() - 1; level >= 0; level--)
    {
        // get the nodes at that level
        vector<int> nodesAtLevel = mp[level];

        // push them into the res array
        for (int i = 0; i < nodesAtLevel.size(); i++)
            res.push_back(nodesAtLevel[i]);
    }

    return res;
}

int main()
{
    /*
        Tree Structure:
            1
           / \
          3   2
    */
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    vector<int> result = reverseLevelOrder(root);

    cout << "Reverse Level Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}