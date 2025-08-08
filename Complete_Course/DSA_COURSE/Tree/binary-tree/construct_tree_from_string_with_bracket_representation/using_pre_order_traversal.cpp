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

Node *preOrder(string &s, int &i)
{
    // string is empty
    if (i > s.length())
        return NULL;

    int val = 0;

    // find value of root node, in case value is more than one digit then this handles it
    while (i < s.length() && s[i] != '(' && s[i] != ')')
    {
        int digit = (s[i] - '0');
        i++;
        val = val * 10 + digit;
    }

    Node *root = new Node(val);

    // left subtree
    if (i < s.length() && s[i] == '(')
    {
        i++; // increment to ignore the opening paranthesis and move to the char
        root->left = preOrder(s, i);
        i++; // increment to ignore the closing paranthesis and move to the begining of the right subtree if exists
    }

    // right subtree
    if (i < s.length() && s[i] == '(')
    {
        i++; // increment to ignore the opening paranthesis and move to the char
        root->right = preOrder(s, i);
        i++; // increment to ignore the closing paranthesis
    }

    return root;
}

Node *treeFromString(string str)
{
    int i = 0;
    return preOrder(str, i);
}

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty())
    {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr)
        {
            cout << "N ";
            continue;
        }
        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(str);
    levelOrder(root);
}