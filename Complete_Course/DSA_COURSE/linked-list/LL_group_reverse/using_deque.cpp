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
//! SC is O(k)
Node *kReverse(Node *head, int k)
{

    // base case
    if (head == NULL || k <= 1)
        return head;

    deque<Node *> dq;
    Node *curr = head;

    while (curr != NULL)
    {

        int count = 0;

        while (curr != NULL && count < k)
        {

            dq.push_back(curr);
            curr = curr->next;
            count++;
        }

        while (!dq.empty())
        {

            Node *front = dq.front();
            Node *last = dq.back();

            swap(front->data, last->data);

            if (!dq.empty())
                dq.pop_front();

            if (!dq.empty())
                dq.pop_back();
        }
    }

    return head;
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