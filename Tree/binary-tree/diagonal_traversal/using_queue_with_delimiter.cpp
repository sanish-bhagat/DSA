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

vector<int> diagonal(Node *root)
{
    if (!root)
        return {};

    vector<int> res;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            // if curr node is nulll and the q is empty then tree has been traversed
            if (q.empty())
                break;

            // if q is not empty then new diagonal level starts, push NULL to identify it
            q.push(NULL);
        }
        else
        {
            while (curr != NULL)
            {
                res.push_back(curr->data);

                if (curr->left)
                    q.push(curr->left);

                curr = curr->right;
            }
        }
    }

    return res;
}

void printList(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    // Create a hard coded tree
    //         8
    //       /   \
    //     3      10
    //    /      /  \
    //   1      6    14
    //         / \   /
    //        4   7 13
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    vector<int> ans = diagonal(root);
    printList(ans);
}