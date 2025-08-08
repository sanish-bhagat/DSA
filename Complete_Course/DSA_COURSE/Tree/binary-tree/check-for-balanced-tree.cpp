#include <iostream>
#include <queue>
using namespace std;

// TC is O(N)
// SC is O(N)

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

//! TC is O(N)
pair<bool, int> isBalancedFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isBalanced(node *root)
{
    return isBalancedFast(root).first;
}

//! TC is O(N*N)
// bool isBalanced(node* root) {
//     //base case
//     if(root == NULL) {
//         return true;
//     }

//     bool left = isBalanced(root -> left);
//     bool right = isBalanced(root -> right);
//     bool diff = abs(height(root -> left) - height(root -> right)) <= 1;

//     if(left && right && diff) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

int main()
{
    node *root = NULL;
    buildTree(root);

    isBalanced(root);
}