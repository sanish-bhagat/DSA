#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *root, vector<int> &nodes)
{
    if (!root)
        return;

    inorder(root->left, nodes);

    nodes.push_back(root->data);

    inorder(root->right, nodes);
}

Node *constructBST(vector<int> &nodes, int start, int end)
{
    // base case
    if (start > end)
        return NULL;

    // get the middle element
    int mid = (start + end) / 2;

    // create the middle element as the root of the subtree
    Node *root = new Node(nodes[mid]);

    // recursivelly build the left and right subtree
    root->left = constructBST(nodes, start, mid - 1);
    root->right = constructBST(nodes, mid + 1, end);

    return root;
}

//! TC is O(n)
//! SC is O(h)

Node *balanceBST(Node *root)
{
    vector<int> nodes;

    // store the inorder of BST into an array
    inorder(root, nodes);

    // recursively build the BST using inorder array
    return constructBST(nodes, 0, nodes.size() - 1);
}

void printLevelOrder(Node *root)
{
    if (root == nullptr)
    {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0)
    {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr)
        {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

int main()
{

    // Constructing an unbalanced BST
    //        4
    //       / \
    //      3   5
    //     /     \
    //    2       6
    //   /		   \
    //  1		    7

    Node *root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    Node *balancedRoot = balanceBST(root);
    printLevelOrder(balancedRoot);

    return 0;
}
