#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
   to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with
   given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void inorder(Node *root, vector<int> &nodes) {
    if(!root)
        return;

    inorder(root -> left, nodes);

    nodes.push_back(root -> data);

    inorder(root -> right, nodes);
}

//! TC is O(n)
//! SC is O(n)

float findMedian(Node *root) {
    vector<int> nodes;
    inorder(root, nodes);

    int n = nodes.size();

    if(n % 2 == 0) {
        return (nodes[n/2] + nodes[n / 2 - 1]) / 2;
    }
    return nodes[n/2];
}

/* Driver program to test above functions*/
int main()
{

    /* Let us create following BST
                  50
               /     \
              30      70
             /  \    /  \
           20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}