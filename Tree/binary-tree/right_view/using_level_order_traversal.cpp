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

vector<int> rightView(Node *root)
{
    if (!root)
        return {};

    vector<int> res;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();

            // get the last node of the level
            if (i == levelSize - 1)
                res.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }

    return res;
}

void printArray(vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{

    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //           / \   
    //          4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);

    printArray(result);

    return 0;
}