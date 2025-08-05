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

Node *reverseKNodes(Node *head, int k) {

    Node *prev = NULL, *curr = head, *nextNode = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    return prev;
}

//! TC is O(n)
//! SC is O(n/k)
Node* kReverse(Node* head, int k) {

    //base case
    if(head == NULL)
        return head;

    Node *groupHead = NULL, *newHead = NULL;
    int count = 0;

    Node *temp = head;

    // temp ko next group pr point krrwao
    while(temp && count < k) {
        temp = temp -> next;
        count++;
    }

    //first k nodes reverse krrlo
    groupHead = reverseKNodes(head, k);

    if(newHead == NULL)
        newHead = groupHead;

    //next group reverse krrlo
    head -> next = reverseKNodes(temp, k);

    return newHead;
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

    print(head);

    int k = 4;

    Node* res = kReverse(head,k);
    print(res);
}