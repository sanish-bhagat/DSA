#include <bits/stdc++.h>
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

class info {
    public:
        int maxi; 
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root, int &ans) {
    //base case
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;

    //max value is always in the right subtree
    currNode.maxi = max(root -> data, right.maxi);

    //min value is always in the left subtree
    currNode.mini = min(root -> data, left.mini);

    if(left.isBST && right.isBST && (left.maxi < root -> data && root -> data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

//!TC is O(n)
//!SC is O(1)
int largestBST(Node* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);

    return maxSize;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
}