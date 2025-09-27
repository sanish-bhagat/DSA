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
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<int> zigZagTraversal(Node *root)
{
    if (!root)
        return {};

    deque<Node *> dq;
    dq.push_back(root);

    vector<int> res;

    bool reverse = false;

    while (!dq.empty())
    {
        int n = dq.size();

        while (n--)
        {
            if (reverse)
            {
                Node *curr = dq.back();
                dq.pop_back();

                res.push_back(curr->data);

                if (curr->right)
                    dq.push_front(curr->right);

                if (curr->left)
                    dq.push_front(curr->left);
            }
            else
            {
                Node *curr = dq.front();
                dq.pop_front();

                res.push_back(curr->data);
                if (curr->left)
                    dq.push_back(curr->left);

                if (curr->right)
                    dq.push_back(curr->right);
            }
        }

        reverse = !reverse;
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

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    vector<int> ans = zigZagTraversal(root);
    printList(ans);

    return 0;
}