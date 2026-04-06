#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// custom comparator for min heap
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// preorder traversal for tree
void preorder(Node *root, vector<string> &res, string curr)
{
    // base case
    if (!root)
        return;

    // push the curr string into the res
    if (!root->left && !root->right)
    {
        res.push_back(curr);
        return;
    }

    // for left, decode with '0'
    preorder(root->left, res, curr + '0');

    // for right, decode with '1'
    preorder(root->right, res, curr + '1');
}

//! TC is O(n)
//! SC is O(n)

vector<string> huffmanCodes(string &s, vector<int> &freq)
{
    int n = freq.size();

    // min heap
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // build minheap with the freq of chars
    for (int f : freq)
    {
        Node *temp = new Node(f);
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

        // build a new node with the sum of freq of the first two min nodes &
        // push it into the min heap
        Node *newNode = new Node(l->data + r->data);
        newNode->left = l;
        newNode->right = r;

        pq.push(newNode);
    }

    // get the preorder huffman coding of the string
    Node *root = pq.top();
    vector<string> res;
    preorder(root, res, "");

    return res;
}

int main()
{
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<string> res = huffmanCodes(s, freq);

    for (string it : res)
        cout << it << " ";
}