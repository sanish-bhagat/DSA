#include <iostream>
#include <map>
using namespace std;

// TC is O(2n)
// SC is O(1)

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

Node *sort012(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;

        else if (temp->data == 1)
            oneCount++;

        else if (temp->data == 2)
            twoCount++;

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);

    print(head);

    head = sort012(head);
    print(head);
}