#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node 
{ 
    public:
    int data; 
    node* left; 
    node* right; 
}; 

node* newNode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 

    return(Node); 
} 

// A utility function to print inorder
// traversal of a given binary tree 
void printInorder(node* node) 
{ 
    if (node == NULL) 
        return; 

    /* first recur on left child */
    printInorder(node->left); 

    cout << node->data << " "; 

    /* now recur on right child */
    printInorder(node->right); 
} 

void inorder(vector<int> &arr, node *root) {
    if(!root)
        return;

    inorder(arr, root -> left);

    arr.push_back(root -> data);

    inorder(arr, root -> right);
}

vector<int> mergeTwoArrays(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size(), m = arr2.size();
    int i =0, j = 0;

    vector<int> ans;

    while(i < n && j < m) {
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n) {
        ans.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

node *arrToBST(vector<int> arr, int low, int high) {
    if(low > high)
        return NULL;

    int mid = (low + high) / 2;

    node *root = newNode(arr[mid]);

    root -> left = arrToBST(arr, low, mid - 1);

    root -> right = arrToBST(arr, mid + 1, high);

    return root;
}

//! TC is O(m + n)
//! SC is O(m + n)

node *mergeTrees(node *root1, node *root2, int n, int m) {
    vector<int> arr1, arr2;

    //get the inorder of both the BST
    inorder(arr1, root1);
    inorder(arr2, root2);

    //merge the inorders of both the BST into an another array
    vector<int> mergedArray = mergeTwoArrays(arr1, arr2);

    //create a BST using the merged array of inorder traversal
    return arrToBST(mergedArray, 0, arr1.size() + arr2.size() - 1);
}

int main() 
{ 
    /* Create following tree as first balanced BST 
        100 
        / \ 
        50 300 
    / \ 
    20 70 
    */
    node *root1 = newNode(100); 
    root1->left     = newNode(50); 
    root1->right = newNode(300); 
    root1->left->left = newNode(20); 
    root1->left->right = newNode(70); 

    /* Create following tree as second balanced BST 
            80 
        / \ 
        40 120 
    */
    node *root2 = newNode(80); 
    root2->left     = newNode(40); 
    root2->right = newNode(120); 

    node *mergedTree = mergeTrees(root1, root2, 5, 3); 

    cout << "Following is Inorder traversal of the merged tree \n"; 
    printInorder(mergedTree); 

    return 0; 
} 