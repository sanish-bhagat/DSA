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

void traverseLeft(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) && (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    // wapas aagye ho
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left part store
    traverseLeft(root->left, ans);

    // traverse leaf node =>

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
}