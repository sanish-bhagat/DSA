#include <iostream>
#include <vector>
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

bool isLeaf(Node *root)
{
    return ((root->left == NULL) && (root->right == NULL));
}

void leftBoundary(Node *root, vector<int> &res)
{
    if (!root)
        return;

    Node *curr = root;

    while (!isLeaf(curr))
    {
        res.push_back(curr->data);

        if (curr->left)
            curr = curr->left;

        else
            curr = curr->right;
    }
}

void rightBoundary(Node *root, vector<int> &res)
{
    if (!root)
        return;

    Node *curr = root;

    vector<int> temp;

    while (!isLeaf(curr))
    {
        temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;

        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

void leafNodes(Node *root, vector<int> &res)
{
    if (!root)
        return;

    Node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            // if it's a leaf node
            if (curr->right == NULL)
                res.push_back(curr->data);

            curr = curr->right;
        }
        else
        {
            // get the inorder predecessor
            Node *pred = curr->left;

            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // if it's predecessor is a leaf node
                if (pred->left == NULL)
                    res.push_back(pred->data);

                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

//! TC is O(n)
//! SC is O(1)

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;

    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    leftBoundary(root->left, res);
    leafNodes(root, res);
    rightBoundary(root->right, res);

    return res;
}

int main()
{

    // Hardcoded Binary tree
    //        20
    //       /  \
    //      8    22
    //     / \     \
    //    4   12    25
    //       /  \
    //      10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);

    vector<int> boundary = boundaryTraversal(root);

    for (int x : boundary)
        cout << x << " ";

    return 0;
}
