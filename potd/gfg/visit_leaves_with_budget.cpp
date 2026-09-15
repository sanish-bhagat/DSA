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

//! TC is O(n)
//! SC is O(n)

int getCount(Node *root, int k)
{
    if (!root)
        return 0;

    // queue for level order traversal
    queue<Node *> q;

    q.push(root);

    int level = 1, cnt = 0;

    while (!q.empty())
    {
        int size = q.size();
        int leafNodes = 0;

        // explore all the nodes in the curr level
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            // keep track of leaf nodes
            if (!node->left && !node->right)
                leafNodes++;

            // push curr node children into queue
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        // no. of leaf nodes that can be visited
        int canVisit = k / level;

        int take = min(canVisit, leafNodes);

        // update ans cnt and reamaining budget
        cnt += take;
        k -= (take * level);

        // no leaf at this or later level can be visited
        if (k < level)
            break;

        level++;
    }

    return cnt;
}

int main()
{

    /*
              10
             /  \
            8    2
           /    / \
          3    3   6
                    /
                   4
    */

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);

    root->right->left = new Node(3);
    root->right->right = new Node(6);

    root->right->right->left = new Node(4);

    int k = 8;

    cout << getCount(root, k);

    return 0;
}