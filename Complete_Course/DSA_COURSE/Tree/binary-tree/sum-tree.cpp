#include <iostream>
#include <queue>
using namespace std;

// TC is O(N)
// SC is O(height)

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

pair<bool, int> isSumTreeFast(node* root) {

    //base case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    //check for leaf node
    if(root -> left == NULL && root -> right == NULL) {
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root -> left);
    pair<bool, int> rightAns = isSumTreeFast(root -> right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condn = root -> data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(left && right && condn) {
        ans.first = true;
        ans.second = root -> data + leftAns.second + rightAns.second;
        //ans.second = 2 * root -> data;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(node* root) {
    return isSumTreeFast(root).first;
}

int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
}