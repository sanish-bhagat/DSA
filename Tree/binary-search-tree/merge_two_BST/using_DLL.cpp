#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// A utility function to print inorder
// traversal of a given binary tree
void printInorder(node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

void bstToDll(node *root, node *&head)
{
    if (!root)
        return;

    bstToDll(root->right, head);

    root->right = head;

    if (head)
        head->left = root;

    head = root;

    bstToDll(root->left, head);
}

node *mergeTwoDll(node *head1, node *head2)
{
    node *head = NULL;
    node *tail = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (!head)
                head = head1;

            else
            {
                tail->right = head1;
                head1->left = tail;
            }

            tail = head1;
            head1 = head1->right;
        }
        else
        {
            if (!head)
                head = head2;

            else
            {
                tail->right = head2;
                head2->left = tail;
            }

            tail = head2;
            head2 = head2->right;
        }
    }

    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

node *dllToBst(node *&head, int n)
{
    if (n <= 0 || !head)
        return NULL;

    node *left = dllToBst(head, n / 2);

    node *root = head;
    root->left = left;
    head = head->right;

    root->right = dllToBst(head, n - (n / 2) - 1);

    return root;
}

//! TC is O(n + m)
//! SC is O(1)

node *mergeTrees(node *root1, node *root2, int n, int m)
{
    // first covert the BSTs into two different DLL
    node *head1 = NULL;
    bstToDll(root1, head1);
    head1->left = NULL;

    node *head2 = NULL;
    bstToDll(root2, head2);
    head2->left = NULL;

    // merge the DLL into sorted form
    node *head = mergeTwoDll(head1, head2);

    // create the BST using that merged DLL
    return dllToBst(head, n + m);
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
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node *mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);

    return 0;
}