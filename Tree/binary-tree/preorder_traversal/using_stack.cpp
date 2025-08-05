#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<int> preOrder(Node *root)
{
    vector<int> res;

    //create a node* type stack and push the root node
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        //get the top element
        Node *curr = st.top();
        st.pop();

        //push the curr node data
        res.push_back(curr->data);

        //first push the right child if it exists
        if (curr->right)
            st.push(curr->right);

        //then the left child if exists, so that the left-subtree is processed first
        if (curr->left)
            st.push(curr->left);
    }

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preOrder(root);

    for (int val : preorder)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}