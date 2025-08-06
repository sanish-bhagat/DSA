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

void inorder(Node* root, vector<int> &inorderVal) {
    if(root == NULL) 
        return;

    inorder(root -> left, inorderVal);
    inorderVal.push_back(root -> data);
    inorder(root -> right, inorderVal);
}

//? Try using vector of node type

//! TC is O(N)
//! SC is O(N)
Node* flatten(Node* root) {
    vector<int> inorderVal;
    //store inorder -> sorted values
    inorder(root, inorderVal);
    int n = inorderVal.size();

    //create a new node
    Node* newRoot = new Node(inorderVal[0]);

    Node* curr = newRoot;

    for(int i=1; i<n; i++) {
        Node* temp = new Node(inorderVal[i]);
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }

    //last node ko null point krrwa do
    curr -> left = NULL;
    curr -> right = NULL;

    return  newRoot;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    root = flatten(root);
    levelOrderTraversal(root);
}