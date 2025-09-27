#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

//! L -> left part mein jao
//! R -> right part mein jao
//! N -> node ko print krwao

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // L
    inorder(root->left);
    // N
    cout << root->data << " ";
    // R
    inorder(root->right);
}

void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // N
    cout << root->data << " ";
    // L
    preorder(root->left);
    // R
    preorder(root->right);
}

void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // L
    postorder(root->left);
    // R
    postorder(root->right);
    // N
    cout << root->data << " ";
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // // creating a tree
    // root = buildTree(root);

    // levelOrderTraversal(root);

    // cout << "Inorder traversal is: ";
    // inorder(root);

    // cout << endl;

    // cout << "Preorder traversal is: ";
    // preorder(root);

    // cout << endl;

    // cout << "Postorder traversal is: ";
    // postorder(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
}