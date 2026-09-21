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

//! TC is O(n)
//! SC is O(n)

bool areAnagrams(Node *root1, Node *root2)
{
    // base case
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;

    // queues for level order traversal
    queue<Node *> q1, q2;

    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty())
    {
        int n1 = q1.size();
        int n2 = q2.size();

        // trees have different no. of nodes in the same level
        if (n1 != n2)
            return false;

        // freq count
        unordered_map<int, int> freq;

        for (int i = 0; i < n1; i++)
        {
            Node *node1 = q1.front();
            q1.pop();

            Node *node2 = q2.front();
            q2.pop();

            // update the frequencies
            freq[node1->data]++;
            freq[node2->data]--;

            // push the child nodes
            if (node1->left)
                q1.push(node1->left);

            if (node1->right)
                q1.push(node1->right);

            if (node2->left)
                q2.push(node2->left);

            if (node2->right)
                q2.push(node2->right);
        }

        // every frequency must be zero if the levels are anagrams
        for (auto it : freq)
            if (it.second != 0)
                return false;
    }

    return q1.empty() && q2.empty();
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    cout << boolalpha << areAnagrams(root1, root2);

    return 0;
}