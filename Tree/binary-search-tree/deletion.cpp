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

Node* minVal(Node* root) {
    Node* temp = root;

    while(temp != NULL) {
        temp = temp -> left;
    }

    return temp;
}

//! TC is O(height)  for worst case O(N)
Node* deleteFromBST(Node* root, int val) {
    //base case
    if(root == NULL)
        return NULL;

    if(root -> data == val) {
        //0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root -> left != NULL && root -> right == NULL) {
            Node * temp = root;
            delete root;
            return temp;
        }

        //right child
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root;
            delete root;
            return temp;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL) {
            //ya toh right subtree se min value or left subtree se max value 
            int mini = minVal(root -> right) -> data;
            root -> data = mini;

            //mini ko delete krrne k liye right subtree mein call maar diya
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val) {
        //left part mein jao
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else {
        //right part mein jao
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    root = deleteFromBST(root, 30);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
}