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

void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;

    inorder(root->left, arr);

    arr.push_back(root->data);

    inorder(root->right, arr);
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;

    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

//! TC is O(n + m)
//! SC is O(n + m)

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    return mergeArrays(arr1, arr2);
}

int main()
{

    // Hard coded binary tree 1
    //           3
    //         /   \
    //       1      5
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Hard coded binary tree 2
    //           4
    //         /   \
    //       2      6
    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> res = merge(root1, root2);
    for (auto val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}