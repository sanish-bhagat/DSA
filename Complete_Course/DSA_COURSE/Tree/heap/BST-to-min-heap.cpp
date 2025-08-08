#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//! TC is O(log N)
Node *insertIntoBST(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // right part me insert krrna h
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // left part mein insert krrna h
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;

            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root, vector<int> &in) {
    //base case
    if(root == NULL)
        return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

void fillPreOrder(Node* root, vector<int> &in, int &index) {
    //base case
    if(root == NULL)
        return;

    root -> data = in[index++];
    fillPreOrder(root -> left, in, index);
    fillPreOrder(root -> right, in, index);
}

//! works when a complete binary tree is given, if not given check for the conditon of complete binary tree
//! Min order -> N < L, N < R and L < R
//! This gives N < L < R (preorder-traversal)

//!TC is O(n)
//! SC is O(n )
Node* BSTtoMinHeap(Node* root) {
    //find the inorder
    vector<int> inOrder;
    inorder(root, inOrder);

    //inorder se preorder traverse krr k tree bnao
    int index = 0;
    fillPreOrder(root, inOrder, index);

    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << endl;

    root = BSTtoMinHeap(root);
    levelOrderTraversal(root);
}