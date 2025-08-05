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

// Function to find the maximum value in the
// left subtree (Predecessor)
Node *rightMost(Node *node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// Function to find the minimum value in
// the right subtree (Successor)
Node *leftMost(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

//! TC is O(h) and SC is O(1)
// This function finds predecessor and successor
// of key in BST. It sets pre and suc as predecesso
// and successor respectively using an iterative approach
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
    Node *curr = root;

    while (curr != nullptr) {
        if (curr->data < key) {
            pre = curr;
            curr = curr->right;
        }
        else if (curr->data > key) {
            suc = curr;
            curr = curr->left;
        }
        else {
          
            // Find the predecessor (maximum
            // value in the left subtree)
            if (curr->left != nullptr)
                pre = rightMost(curr->left);

            // Find the successor (minimum
            // value in the right subtree)
            if (curr->right != nullptr)
                suc = leftMost(curr->right);

            break;
        }
    }
}

Node* inorderSuccessor(Node* root, int val) {
    Node* succ = NULL;

    while(root != NULL) {
        if(val >= root -> data) {
            root = root -> right;
        }
        else {
            succ = root;
            root = root -> left;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int val) {
    Node* pred = NULL;

    while(root != NULL) {
        if(val > root -> data) {
            pred = root;
            root = root -> right;
        }
        else {
            root = root -> left;
        }
    }
    return pred;
}

void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);

    cout << root -> data << " ";

    inorderTraversal(root -> right);
}

//! Inorder traversal approach
//! TC is O(N) and SC is O(N)
// Function to find the predecessor and successor
// of a given key in BST
void findPreSuc(Node* root, int key, Node*& pre, Node*& suc) {
  
    // If root is null, return
    if (!root)
        return;

    // Traverse the left subtree
    findPreSuc(root->left, key, pre, suc);

    // The first greater value seen is successor
    if (root->data > key) {        
        if (!suc || (suc && suc->data > root->data))
            suc = root;
    }
  
    // The last smaller value seen is predecessor
    else if (root->data < key)
        pre = root;

    // Traverse the right subtree
    findPreSuc(root->right, key, pre, suc);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << endl;
    inorderTraversal(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;

    Node* pre = NULL;
    Node* succ = NULL;

    // findPreSuc(root, pre, succ, 20);
    // cout << pre -> data << endl;
    // cout << succ -> data << endl;

    if(inorderSuccessor(root, 20) != NULL)
        cout << "Inorder Successor " << inorderSuccessor(root, 20) -> data << endl; 
    else 
        cout << "No Successor" << endl;
    // cout << "Inorder Predecessor " << inorderPredecessor(root, 20) -> data << endl; 

    if(inorderPredecessor(root, 20) != NULL)
        cout << "Inorder Predecessor " << inorderPredecessor(root, 20) -> data << endl; 
    else 
        cout << "No Predecessor" << endl;
}