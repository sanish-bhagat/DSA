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

bool checkTree(Node *root2, map<pair<int, int>, bool> visited)
{
    // first node is not visited in second tree then return false, i.e both trees have different root then return false
    if (visited[{root2->data, -1}] == false)
        return false;

    queue<Node *> q;
    q.push(root2);

    // traverse the second tree and check if nodes are visited or not
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // if left child is not visited then return false
        if (curr->left)
        {
            if (visited[{curr->left->data, curr->data}] == false)
                return false;

            q.push(curr->left);
        }

        // if right child is not visited
        if (curr->right)
        {
            if (visited[{curr->right->data, curr->data}] == false)
                return false;

            q.push(curr->right);
        }
    }

    return true;
}

//! TC is O(n)
//! SC is O(n)

bool isIsomorphic(Node *root1, Node *root2)
{
    // map the node's value to their parent
    map<pair<int, int>, bool> visited;

    // mark first node as visited
    visited[{root1->data, -1}] = true;

    queue<Node *> q;
    q.push(root1);

    // traverse the first tree and mark nodes as visited
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            visited[{curr->left->data, curr->data}] = true;
            q.push(curr->left);
        }

        if (curr->right)
        {
            visited[{curr->right->data, curr->data}] = true;
            q.push(curr->right);
        }
    }

    // check the second tree
    return checkTree(root2, visited);
}

int main()
{

    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       / \
    //      7   8
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      3   2
    //     /   / \
    //    6   4   5
    //           / \
    //          8   7
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    // root2->left->left = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    if (isIsomorphic(root1, root2))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}