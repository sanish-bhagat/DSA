//! Approach 2 =>
//! Step1 - convert BST into sorted LL
//! Step2 - merge 2 sorted LL
//! Step3 - sorted LL -> BST

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//! TC is O(log N)
Node *insertIntoBST(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // right part me insert krrna h
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // left part mein insert krrna h
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;

            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void convertIntoSortedDLL(Node *root, Node *&head)
{
    if (root == NULL)
        return;

    // right subtree ko LL mein convert krrdo
    convertIntoSortedDLL(root->right, head);

    root->right = head;

    // check krro ki right subtree se NULL return hua h ya nhi
    if (head != NULL)
        head->left = root;

    head = root;

    // left subtree ko convert krrdo
    convertIntoSortedDLL(root->left, head);
}

Node *mergeLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node *&head)
{
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *sortedLLToBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = sortedLLToBST(head, n / 2);

    Node *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

//! TC is O(m + n)
//!  SC is O(h1 + h2)
Node *mergeTwoBST(Node *root1, Node *root2)
{
    // step1 - convert BST to DLL in-place
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // step2 - merge sorted LL
    Node *head = mergeLL(head1, head2);

    // step3 - convert SLL to BST
    return sortedLLToBST(head, countNodes(head));
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
}