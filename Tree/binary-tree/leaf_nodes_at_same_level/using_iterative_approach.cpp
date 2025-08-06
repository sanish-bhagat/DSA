#include <bits/stdc++.h>
using namespace std;

// tree node
struct Node
{
    int data;
    Node *left, *right;
};

// returns a new tree Node
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//! TC is O(n)
//! SC is O(n)

bool check(Node *root)
{
    if (!root)
        return true;

    queue<Node *> q;
    q.push(root);

    bool flag = false;

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);

            //if it is a leaf node, update flag
            if (temp->left == NULL && temp->right == NULL)
                flag = true;
        }

        // if there exists more levels then there exist atleast one leaf node
        if (flag && !q.empty())
            return false;
    }

    return true;
}

int main()
{
    // Let us create tree shown in third example
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    // getchar();
    return 0;
}