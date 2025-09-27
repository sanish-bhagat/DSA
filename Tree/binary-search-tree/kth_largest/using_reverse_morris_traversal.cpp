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
//! SC is O(1)

int kthLargest(Node *root, int k)
{
    if (!root)
        return -1;

    int cnt = 0;
    Node *curr = root;

    // traverse the tree using reverse morris traversal
    while (curr)
    {
        // if curr -> right not exists, then check the condn
        if (curr->right == NULL)
        {
            cnt++;
            if (cnt == k)
                return curr->data;

            // move curr to its left
            curr = curr->left;
        }

        // if right exists, then
        else
        {
            // find the inorder succ(leftmost nodes in right subtree)
            Node *succ = curr->right;

            while (succ->left && succ->left != curr)
                succ = succ->left;

            // create the thread
            if (succ->left == NULL)
            {
                succ->left = curr;
                curr = curr->right;
            }
            // remove the thread, and check the condn
            else
            {
                succ->left = NULL;
                cnt++;

                if (cnt == k)
                    return curr->data;

                // move curr to its left
                curr = curr->left;
            }
        }
    }
    return -1;
}

int main()
{

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12
    //      /  \
    //     10   14
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    int k = 3;

    cout << kthLargest(root, k) << endl;

    return 0;
}