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

void convertToLL(Node *root, Node *&head, Node *&tail)
{
    if (!root)
        return;

    convertToLL(root->left, head, tail);

    if (!head)
        head = tail = root;

    else
    {
        tail->right = root;
        root->left = tail;
        tail = root;
    }

    convertToLL(root->right, head, tail);
}

//! TC is O(n + m)
//! SC is O(n + m)

vector<int> merge(Node *root1, Node *root2)
{
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    convertToLL(root1, head1, tail1);
    convertToLL(root2, head2, tail2);

    vector<int> ans;

    Node *curr1 = head1, *curr2 = head2;

    while (curr1 && curr2)
    {
        if (curr1->data < curr2->data)
        {
            ans.push_back(curr1->data);
            curr1 = curr1->right;
        }
        else
        {
            ans.push_back(curr2->data);
            curr2 = curr2->right;
        }
    }

    while (curr1)
    {
        ans.push_back(curr1->data);
        curr1 = curr1->right;
    }

    while (curr2)
    {
        ans.push_back(curr2->data);
        curr2 = curr2->right;
    }

    return ans;
}

int main()
{

    // Hard coded binary tree 1
    //           3
    //         /   \
    //       1      5
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Hard coded binary tree 2
    //           4
    //         /   \
    //       2      6
    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> res = merge(root1, root2);
    for (auto val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}