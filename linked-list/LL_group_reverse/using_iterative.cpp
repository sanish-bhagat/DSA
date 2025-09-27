#include <bits/stdc++.h>
using namespace std;

// TC is O(n)
// SC is O(n)

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            // memory is free
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    // create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{

    // create a new node
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << " List is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//! TC is O(n)
//! SC is O(1)
Node *kReverse(Node *head, int k)
{

    // base case

    if (head == nullptr)
    {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr)
    {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // If newHead is null, set it to the
        // last node of the first group
        if (newHead == nullptr)
        {
            newHead = prev;
        }

        // Connect the previous group to the
        // current reversed group
        if (tail != nullptr)
        {
            tail->next = prev;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);

    print(head);

    int k = 4;

    Node *res = kReverse(head, k);
    print(res);
}