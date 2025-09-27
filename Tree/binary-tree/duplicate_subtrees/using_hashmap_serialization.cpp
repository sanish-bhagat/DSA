#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

string serializeArray(Node *root, unordered_map<string, int> &mpp, vector<Node *> &ans)
{
    if (!root)
        return "N";

        //recursive calls for left and right subtree
    string left = serializeArray(root->left, mpp, ans);
    string right = serializeArray(root->right, mpp, ans);

    //convert the curr root value into string
    string val = to_string(root->data);

    //serialize the curr subtree
    string curr = "(" + left + ")" + val + "(" + right + ")";

    //increase the frequency of the curr serialized subtree in the map
    mpp[curr]++;

    //if the serialzied subtree repeats then push in the result array
    if (mpp[curr] == 2)
        ans.push_back(root);

    //return the curr serailized array for the upeer subtree
    return curr;
}

//! TC is O(n * n)
//! SC is O(n)

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> ans;
    unordered_map<string, int> mpp;

    serializeArray(root, mpp, ans);

    return ans;
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(4);

    vector<Node *> ans = printAllDups(root);

    for (Node *node : ans)
    {
        preOrder(node);
        cout << endl;
    }

    return 0;
}