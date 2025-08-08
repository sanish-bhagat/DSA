#include <iostream>
using namespace std;

//TC is O(n)
//SC is O(1)

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

Node* floydDetectLoop(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast -> next;

        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "Present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
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

    if(floydDetectLoop(head) != NULL) {
        cout << "Cycle is present" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }

    Node* res = getStartNode(head);
    cout << "Starting node is " << res -> data << endl;
}