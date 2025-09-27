//! Approach 1 =>
//! Step1 - dono BST ka inorder nikal lo
//! Step2 - merge 2 sorted arrays krrdo, ek naya sorted array mil jayega
//! inorder to BST wala function

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

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }

    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

Node *inorderToBST(int s, int e, vector<int> &in)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    Node *root = new Node(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

//! TC is O(m + n)
//! SC is O(m + n)
Node *mergeTwoBST(Node *root1, Node *root2)
{
    // step 1 - store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 - merge both sorted arrays
    vector<int> mergeArray = merge(bst1, bst2);

    // step 3 - use merged inorder array to build BST
    int s = 0, e = mergeArray.size() - 1;
    return inorderToBST(s, e, mergeArray);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
}