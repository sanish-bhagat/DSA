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

//! TC is O(n1 + n2)
//! SC is O(h1 + h2)

int countPairs(Node *root1, Node *root2, int x)
{
    if (!root1 || !root2)
        return 0;

    int cnt = 0;

    // traverse the 1st BSt in in-order
    // 2nd BSt in reverse in-order
    stack<Node *> st1, st2;
    Node *top1, *top2;

    while (true)
    {
        while (root1)
        {
            st1.push(root1);
            root1 = root1->left;
        }

        while (root2)
        {
            st2.push(root2);
            root2 = root2->right;
        }

        if (st1.empty() || st2.empty())
            break;

        top1 = st1.top();
        top2 = st2.top();

        // if sum matches then move both ptr to next nodes
        if (top1->data + top2->data == x)
        {
            cnt++;

            st1.pop();
            st2.pop();

            root1 = top1->right;
            root2 = top2->left;
        }

        // move the ptr to larger value in 1st BST
        else if (top1->data + top2->data < x)
        {
            st1.pop();
            root1 = top1->right;
        }

        // move the ptr to smaller value in 2nd BSt
        else
        {
            st2.pop();
            root2 = top2->left;
        }
    }

    return cnt;
}

int main()
{

    // BST1
    //    2
    //  /  \
    // 1   3
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    // BST2
    //    5
    //  /  \
    // 4   6
    Node *root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);

    int x = 6;
    cout << countPairs(root1, root2, x);

    return 0;
}