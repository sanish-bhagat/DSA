#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *bottom;

    Node(int newdata)
    {
        data = newdata;
        next = bottom = nullptr;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

//! TC is O(n * m * log n)
//! SC is O(n)

Node *flatten(Node *root)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    // push sthe first level nodes in min heap
    while (root != NULL)
    {
        pq.push(root);
        root = root->next;
    }

    Node *head = NULL, *tail = NULL;

    while (!pq.empty())
    {
        auto minNode = pq.top();
        pq.pop();

        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->bottom = minNode;
            tail = tail->bottom;
        }

        // if another node is present ini the bottom of the popped node, then push it into min heap
        if (minNode->bottom)
        {
            pq.push(minNode->bottom);
            // make the bottom ptr NULL
            minNode->bottom = NULL;
        }
    }

    return head;
}

int main()
{

    // Create a hard-coded linked list:
    //   5 -> 10 -> 19 -> 28
    //   |    |     |
    //   V    V     V
    //   7    20    22
    //   |          |
    //   V          V
    //   8          50
    //   |
    //   V
    //   30

    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flatten(head);

    printList(head);
    return 0;
}