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

int serializeTree(Node *root, unordered_map<int, int> &mpp, unordered_map<string, int> &strToInt, int &idNum, vector<Node *> &ans)
{
    if (!root)
        return 0;

    // recursive call for left and right subtree
    int left = serializeTree(root->left, mpp, strToInt, idNum, ans);
    int right = serializeTree(root->right, mpp, strToInt, idNum, ans);

    string val = to_string(root->data);

    // serialize the subtree
    string curr = "(" + to_string(left) + ")" + val + "(" + to_string(right) + ")";

    // integer id for serialized subtree string
    int currId;

    // if id already exists
    if (strToInt.find(curr) != strToInt.end())
        currId = strToInt[curr];

    // else assign a new id
    else
    {
        currId = idNum++;
        strToInt[curr] = currId;
    }

    // increament the frequency of the currid in the map
    mpp[currId]++;

    // if subtree exists already then add to the result
    if (mpp[currId] == 2)
        ans.push_back(root);

    return currId;
}

//! TC is O(n)
//! SC is O(n)

vector<Node *> printAllDups(Node *root)
{
    // map the unique id string with their frequency
    unordered_map<int, int> mpp;

    // map serialized string with their ids
    unordered_map<string, int> strToInt;
    vector<Node *> ans;

    // unique integer id
    int idNum = 1;

    serializeTree(root, mpp, strToInt, idNum, ans);

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