#include <bits/stdc++.h>
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

//! if we use this fucntion TC will be => O(N * N)
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

//! TC will be => O(N log N)
node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // preorder mein se element nikal lo
    int element = pre[index++];

    // root element bna do
    node *root = new node(element);

    // inorder mein element ka position find krrlo
    int position = nodeToIndex[element];
    // int position = findPosition(in, element, n);

    // recursive calls
    root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

    return root;
}

node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    // create nodes to index mapping
    createMapping(in, nodeToIndex, n);
    node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

int main()
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};

    node *root = buildTree(in, pre, 6);
    levelOrderTraversal(root);
}