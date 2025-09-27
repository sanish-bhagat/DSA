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

//! TC is O(N)
//! SC is O(1)
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    if(root == NULL) {
        pair<int, int> p = make_pair(NULL, NULL);
        return p;
    }

    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp != NULL) {
        if(temp -> data > key) {
            succ = temp -> data;
            temp = temp -> left;
        }
        else if(temp-> data == key)
            break;
        else {
            pred = temp-> data;
            temp = temp -> right;
        }
    }

    if(temp == NULL)
        return make_pair(pred,succ);

    //leftTree mein max value pred hoga
    Node* leftTree = temp -> left;
    while(leftTree != NULL) {
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }

    //rightTree mein min value succ hoga
    Node* rightTree = temp -> right;
    while(rightTree != NULL) {
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }

    return make_pair(pred, succ);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << predecessorSuccessor(root, 20).first << "  " << predecessorSuccessor(root, 20).second;
}