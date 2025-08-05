#include <iostream>
#include <map>
using namespace std;

//TC is O(n)
//SC is O(n)

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node() {
        int value = this-> data;

        if(this-> next != NULL) {
            //memory is free
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertAtHead(Node* &head, int data) {

    //create a new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data) {

    //create a new node
    Node* temp = new Node(data);
    tail -> next = temp;
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
void removeLoop(Node *head) {

    if(head == NULL)
        return;

    Node *slow = head, *fast = head;

    slow = slow -> next;
    fast = fast -> next -> next;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    //loop detect hogya h
    if(slow == fast) {

        slow = head;

        //agar slow and fast dono hi head ko point krr rha h toh fast ko aage badhao
        if(slow == fast) {

            while(fast -> next != slow)
                fast = fast -> next;
        }
        else {
            while(slow -> next != fast -> next) {
                slow = slow -> next;
                fast = fast -> next;
            }
        }

        //fast loop ka last node ko detect krrega, toh uske next pointer ko null krrdo
        fast -> next = NULL;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);

    tail -> next = head -> next;

    // print(head);

    // removeLoop(head);
}