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

// return the index of closing parenthesis
int findIndex(string str, int i, int j)
{
    int count = 0;

    for (int k = i; k <= j; k++)
    {
        if (str[k] == '(')
            count++;

        else if (str[k] == ')')
            count--;

        if (count == 0)
            return k;
    }

    return -1;
}

Node *treeFromStringRec(string str, int i, int j)
{
    // base case
    if (i > j)
        return NULL;

    int val = 0;

    // if in case value is more than one digit
    while (i <= j && str[i] >= '0' && str[i] <= '9')
    {
        val *= 10;
        val += (str[i] - '0');
        i++;
    }

    // new root
    Node *root = new Node(val);
    int index = -1;

    // if next char is '(' then find the index of its compliment ')'
    if (i <= j && str[i] == '(')
        index = findIndex(str, i, j);

    // if index found, build the left and right subtree recursively
    if (index != -1)
    {
        root->left = treeFromStringRec(str, i + 1, index - 1);
        root->right = treeFromStringRec(str, index + 2, j - 1);
    }

    return root;
}

//! TC is O(n * n)
//! SC is O(n)

Node *treeFromString(string str)
{
    Node *root = treeFromStringRec(str, 0, str.length() - 1);
    return root;
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