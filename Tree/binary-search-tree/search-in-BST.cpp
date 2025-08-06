#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//! TC is O(log N)
Node* insertIntoBST(Node* root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> data) {
        //right part me insert krrna h
        root -> right = insertIntoBST(root -> right, data);
    } 
    else {
        //left part mein insert krrna h
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
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

//! Iteraative way
//! TC is O(log N)   for worst case O(height)
//! SC is O(1)
// bool searchInBST(Node* root, int x) {
//     Node *temp = root;

//     while(temp != NULL) {
//         if(temp -> data == x)
//             return true;

//         if(temp -> data > x)
//             temp = temp -> left;
//         else 
//             temp = temp -> right;
//     }

//     return false;
// }

//! Recursive way
//! TC is O(log N)   for worst case O(height)
//! SC is O(height)
bool searchInBST(Node* root, int x) {
    //base case
    if(root == NULL)
        return false;
    
    if(root -> data == x)
        return true;

    if(root -> data > x)
        searchInBST(root -> left, x);
    else 
        searchInBST(root -> right, x);
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);

    cout << searchInBST(root, 25);
}