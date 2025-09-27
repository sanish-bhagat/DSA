#include <iostream>
using namespace std;

//TC is O(n)
//SC is O(n)

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
        int val = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for " << val << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {

        // non-empty list
        // assuming element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found = curr is representing element wala node
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{

    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do 
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

bool isCircularList(Node* head) {

    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;

    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }

    if(temp == head) {
        return true;
    }

    return false;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    if(isCircularList(tail)) {
        cout << "Linked List is circular" << endl;
    } else {
        cout << "Linked List is not circular" << endl;
    }
}