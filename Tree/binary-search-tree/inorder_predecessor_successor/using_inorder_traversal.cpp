#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<Node *> findPreSuc(Node *root, int key)
{
    vector<Node *> result;
    Node *pred = NULL;
    Node *succ = NULL;

    if (!root)
        return result;

    while (root != NULL)
    {
        // it may be a pred store it and move to the right subtree, for succ
        if (root->data < key)
        {
            pred = root;
            root = root->right;
        }
        // it may be a succ store it and move to the left subtree, for pred
        else if (root->data > key)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            // root -> data == key, then
            //  pred -> find the rightmost node of the left subtree
            //  succ -> find the leftmost node of the right subtree
            if (root->left)
            {
                Node *temp = root->left;
                while (temp->right != NULL)
                    temp = temp->right;

                pred = temp;
            }
            if (root->right)
            {
                Node *temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;

                succ = temp;
            }
            break;
        }
    }

    // push the pred an succ into the result
    result.push_back(pred ? pred : NULL);
    result.push_back(succ ? succ : NULL);

    return result;
}

int main()
{
    int key = 65;

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->right = new Node(80);
    root->right->left = new Node(60);

    // Find predecessor and successor
    vector<Node *> result = findPreSuc(root, key);

    // Output the result
    if (result[0] != nullptr)
        cout << result[0]->data << " ";
    else
        cout << -1 << " ";

    if (result[1] != nullptr)
        cout << result[1]->data << endl;
    else
        cout << -1 << endl;

    return 0;
}