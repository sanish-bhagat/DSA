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

//! Recursive way
//!TC is O(N)
//! SC is O(H)
Node* LCAinBST(Node* root, int p, int q) {
    //base case
    if(root == NULL)
        return NULL;

    if(root -> data < p && root -> data < q) 
        return LCAinBST(root -> right, p ,q);
    
    if(root -> data > p && root -> data > q) 
        return LCAinBST(root -> left, p ,q);

    //agar yaha tak pahuch gye ho iska mtlb h ki yahi ans h
    //(root -> data > a && root -> data < b) ya phir (root -> data < a && root -> data > b) yaha pahuch gye ho iska mtlb ye condition reach ho gya h
    return root;
}

//! Iterative way
//!TC is O(N)
//! SC is O(1)
// Node* LCAinBST(Node* root, int p, int q) {
//     while(root != NULL) {
//         if(root -> data > p && root -> data > q) {
//             root = root -> left;
//         }
//         else if(root -> data < p && root -> data < q) {
//             root = root -> right;
//         }
//         else {
//             return root;
//         }
//     }
// }

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << LCAinBST(root, 7, 9) -> data;
}