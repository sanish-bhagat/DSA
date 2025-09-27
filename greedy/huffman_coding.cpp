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
        left = right = NULL;
    }
};

// custom class for min heap
class Compare
{
public:
    // By returning true when a->data > b->data, we flip the ordering so that the smallest element appears first
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

void preorder(Node *root, vector<string> &ans, string curr)
{
    if (!root)
        return;

    // push the curr string into the ans
    if (!root->left && !root->right)
    {
        ans.push_back(curr);
        return;
    }

    // for left, decode with '0'
    preorder(root->left, ans, curr + '0');

    // for right, decode with '1'
    preorder(root->right, ans, curr + '1');
}

//! TC is O(n * logn)
//! SC is O(n)

vector<string> huffmanCodes(string &s, vector<int> freq)
{
    int n = s.length();

    // min heap
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // build minheap with the freq of chars
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(freq[i]);
        pq.push(temp);
    }

    // traverse min heap and build the huffman tree
    while (pq.size() >= 2)
    {
        // first min freq node
        Node *l = pq.top();
        pq.pop();

        // second min freq node
        Node *r = pq.top();
        pq.pop();

        // build a new node with the sum of freq of the first two min nodes & push it into the min heap
        Node *newNode = new Node(l->data + r->data);
        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    // get the preorder huffman coding of the string
    vector<string> ans;
    Node *root = pq.top();
    preorder(root, ans, "");

    return ans;
}

int main()
{
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    vector<string> ans = huffmanCodes(s, freq);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}