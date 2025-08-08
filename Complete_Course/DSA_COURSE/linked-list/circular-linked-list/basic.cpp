#include <iostream>
using namespace std;

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

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    } else {

        //non-empty
        //assuming value is present

        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node linked list
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 9, 11);
    // print(tail);

    // insertNode(tail, 5, 6);
    // print(tail);

    // insertNode(tail, 3, 4);
    // print(tail);

    // insertNode(tail, 11, 13);
    // print(tail);

    deleteNode(tail,5);
    print(tail);
}