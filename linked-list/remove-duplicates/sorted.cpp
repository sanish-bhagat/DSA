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

//using recursion ( TC is O(N))
void usingRecursion(Node* head) {

    if(head == NULL) {
        return;
    }

    if(head -> next != NULL) {
        if(head -> data == head -> next -> data) {
            head -> next = head -> next -> next;
            usingRecursion(head);
        } else {
            usingRecursion(head -> next);
        }
    }
}

Node* uniqueSortedList(Node* head) {

    //empty list
    if(head == NULL) {
        return NULL;
    }

    //non-empty list
    Node* curr = head;

    while(curr != NULL && curr-> next != NULL) {
        
        if(curr -> data == curr -> next -> data) {
            Node* next_next = curr -> next -> next;
            // Node* nodeToDelete = curr -> next;
            // delete(nodeToDelete);
            curr -> next = next_next;
        } else {
            curr = curr -> next;
        }
    }

    return head;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,13);

    print(head);    

    // head = uniqueSortedList(head);
    // print(head);

    usingRecursion(head);
    print(head);
}