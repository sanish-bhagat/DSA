#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int val, int &suc)
{
    if (!root)
        return newNode(val);

    if (val >= root->data)
        root->right = insert(root->right, val, suc);

    else
    {
        suc = root->data;
        root->left = insert(root->left, val, suc);
    }

    return root;
}

//! TC is O(n * n)
//! SC is O(h)

void replace(int arr[], int n)
{
    Node *root = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        int suc = -1;

        root = insert(root, arr[i], suc);

        arr[i] = suc;
    }
}

int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92,
                 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    replace(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}