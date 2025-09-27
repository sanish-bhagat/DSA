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

Node* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if(i >= preorder.size())
        return NULL;

    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    //yaha tak pahuch gye ho mtlb element range mein lie krrta h
    Node* root = new Node(preorder[i++]);
    root -> left = solve(preorder, mini, root -> data, i); 
    root -> right = solve(preorder, root -> data, maxi, i); 
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

int main()
{
    Node *root = NULL;

    // cout << "Enter data to create BST" << endl;
    // takeInput(root);

    // cout << "Printing the BST" << endl;
    // levelOrderTraversal(root);
    // cout << endl;

    vector<int> p = {10 ,20,5,15,13,35,30,42};

    root = preorderToBST(p);
    levelOrderTraversal(root);
}