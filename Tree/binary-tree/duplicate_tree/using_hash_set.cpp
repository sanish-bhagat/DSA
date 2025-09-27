#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left, *right;
    Node(char x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

string dupSubRec(Node *root, unordered_set<string> &s, int &ans)
{
    if (!root)
        return "N";

    // if leaf node return its value as a string
    if (root->left == NULL && root->right == NULL)
        return to_string(root->data);

    // traverse the left and right subtrees
    string left = dupSubRec(root->left, s, ans);
    string right = dupSubRec(root->right, s, ans);

    string curr = "";
    curr += to_string(root->data);

    // if left and right subtrees are not empty(focus on nodes where both children are leaf node or one is a leaf node and other is a NULL)
    if (left != "" && right != "")
    {
        curr += "*";
        curr += left;
        curr += "*";
        curr += right;
    }
    // if the lft and right are empty, then no need to process just return an emtpy string
    else
        return "";

    // if the curr serialised string is present in set set the ans to 1(true), else insert the string into set
    if (s.find(curr) != s.end())
        ans = 1;
    else
        s.insert(curr);

    // retrun an empty string for each processed subtree as upper subtrees don't need further processing
    return "";
}

//! TC is O(n)
//! SC is O(n)

int dupSub(Node *root)
{
    // var to know if tree contains duplicate or not
    int ans = 0;

    // set used for storing serialized form of string
    unordered_set<string> s;

    dupSubRec(root, s, ans);

    return ans;
}

int main()
{

    //         A
    //       /   \
    //      B     C
    //     / \     \
    //    D   E     B
    //           /   \
    //          D     E
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left = new Node('D');

    if (dupSub(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}