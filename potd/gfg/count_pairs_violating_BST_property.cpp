#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (!root)
        return;

    inorderTraversal(root->left, inorder);

    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

int merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left, k = 0;
    int j = mid + 1;
    int invCount = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
        {
            // count inversions with remaining left elements
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    return invCount;
}

int mergeSort(vector<int> &arr, int left, int right)
{
    int invCount = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid, right);
    }

    return invCount;
}

//! TC is O(n logn)
//! SC is O(n)

int pairsViolatingBST(Node *root)
{
    // inorder of BST
    vector<int> inorder;
    inorderTraversal(root, inorder);

    // count inversion's using merge sort algo
    return mergeSort(inorder, 0, inorder.size() - 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(40);

    root->right->left = new Node(20);
    root->right->right = new Node(30);

    cout << pairsViolatingBST(root) << endl;

    return 0;
}