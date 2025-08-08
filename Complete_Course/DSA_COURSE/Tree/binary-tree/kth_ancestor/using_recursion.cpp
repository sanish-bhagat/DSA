#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};


Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool ancestor(Node *root, int &k, int node, int &res) {
    if(!root)
        return false;

    //if found the element whose ancestor is to be searched then move one level up
    if(root -> data == node) {
        k -= 1;
        return true;
    }
    else {

        //check in left side
        bool flag = ancestor(root ->left, k,node, res);

        if(flag) {
            //if count is 0 then kth ancestor is found, return false so that no more computation is done
            if(k == 0) {
                res = root -> data;
                return false;
            }

            //if count != 0, this is not the ancestor we are lookin for, so move one level up
            k-= 1;
            return true;
        }

        //check in the right side
        bool flag2 = ancestor(root -> right, k, node, res);
        if(flag2) {
            if(k ==0) {
                res = root -> data;
                return false;
            }

            k-= 1;
            return true;
        }
    }
}

//! TC is O(n)
//! SC is O(n)
 
int kthAncestor(Node *root, int k, int node) {
    int res = -1;
    ancestor(root, k, node, res);

    return res;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    cout<<kthAncestor(root,k,node);
    return 0;
}