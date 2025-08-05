#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int lCount;
    Node *left;
    Node *right;
    Node(int x, int l)
    {
        data = x;
        lCount = l;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(k)
//! SC is O(1)

int kthSmallest(Node *root, int k)
{
    int cnt = 0;
    Node *curr = root;

    // travere the BST using morris traversal while maintiaing a cnt of the nodes traversed
    while (curr)
    {
        if (curr->left == NULL)
        {
            cnt++;

            if (cnt == k)
                return curr->data;

            curr = curr->right;
        }
        else
        {
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
                pred->right = NULL;

                cnt++;

                if (cnt == k)
                    return curr->data;

                curr = curr->right;
            }
        }
    }

    return -1;
}

int main()
{

    // Binary search tree
    //      20
    //    /   \
    //   8     22
    //  / \
    // 4   12
    //    /  \
    //   10   14
    Node *root = new Node(20, 5);
    root->left = new Node(8, 1);
    root->right = new Node(22, 0);
    root->left->left = new Node(4, 0);
    root->left->right = new Node(12, 1);
    root->left->right->left = new Node(10, 0);
    root->left->right->right = new Node(14, 0);
    int k = 3;

    cout << kthSmallest(root, k) << endl;
    return 0;
}