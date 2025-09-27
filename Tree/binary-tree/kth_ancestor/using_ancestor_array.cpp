#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int countNodes(Node *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void generateAncestor(Node *root, int ancestors[])
{
    // ancestor of root node is always -1
    ancestors[root->data] = -1;

    // use level order traversal to traverse the tree
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // ancestor of the child will be its parent node
        if (curr->left)
        {
            ancestors[curr->left->data] = curr->data;
            q.push(curr->left);
        }

        if (curr->right)
        {
            ancestors[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }
}

//! TC is O(n)
//! SC is O(n)

int kthAncestor(Node *root, int k, int node)
{
    // count the total no. of nodes
    int n = countNodes(root);

    // to store the ancestor of each node(size is n+1 to match the node's values with their indices)
    int ancestors[n + 1];

    generateAncestor(root, ancestors);

    // to loop through ancestor array
    int count = 0;

    while (node != -1)
    {
        // update the value of the node by its ancestor
        node = ancestors[node];
        count++;

        if (count == k)
            break;
    }

    return node;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    cout << kthAncestor(root, k, node);
    return 0;
}