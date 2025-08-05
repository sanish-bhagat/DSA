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

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node *root, int index, int cnt)
{
    if (root == NULL)
        return true;

    if (index >= cnt)
        return false;
    else
    {
        bool left = isCBT(root, 2 * index, cnt);      // for 0-based indexing 2*index + 1
        bool right = isCBT(root, 2 * index + 1, cnt); // for 0-based indexing 2*index + 2
        return (left && right);
    }
}

bool isMaxOrder(Node *root)
{
    // leaf node
    // if (root->left == NULL && root->right == NULL)
    //     return true;

    // // only the left child exist
    // if (root->right == NULL)
    //     return (root->data > root->left->data);

    // else
    // {
    //     bool left = isMaxOrder(root->left);
    //     bool right = isMaxOrder(root->right);

    //     return (left && right && (root->data > root->left->data && root->data > root->right->data));
    // }

    if(root == NULL) 
        return true;

    bool left = isMaxOrder(root -> left);
    bool right = isMaxOrder(root -> right);

    if(root -> left != NULL && root -> data < root -> left -> data)
        return false;

    if(root -> right != NULL && root -> data < root -> right -> data)
        return false;

    return (left && right);
}

//! TC is O(N)
//! SC is O(h)
bool isHeap(Node *root)
{
    int index = 0;
    int totalCount = countNodes(root);

    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
}