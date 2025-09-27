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
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

int getCount(Node *root, int l, int h)
{
    int cnt = 0;

    queue<Node *> q;
    q.push(root);

    // traverse the BST in level-order manner
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // node falls in the range, increment count and push both its child
        if (curr->data >= l && curr->data <= h)
        {
            cnt++;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        else
        {
            // if node value is smaller than lower limit then traverse the right subtree
            if (curr->data < l)
            {
                if (curr->right)
                    q.push(curr->right);
            }

            // if node value is larger than upper limit then traverse the left subtree
            if (curr->data > h)
            {
                if (curr->left)
                    q.push(curr->left);
            }
        }
    }

    return cnt;
}

int main()
{

    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50
    //     /   /  \    
    //    1   40  100
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;

    cout << getCount(root, l, h) << endl;

    return 0;
}