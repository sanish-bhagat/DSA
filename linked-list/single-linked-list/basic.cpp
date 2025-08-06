#include <iostream>
#include <map>
using namespace std;

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

void insertAtPosition(Node* &head,Node* &tail,int position,int data) {
    
    //insert at start
    if(position == 1) {
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp-> next;
        cnt++;
    }

    //insert at last position
    if(temp-> next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    //creating a node for data
    Node* nodeToInsert = new Node(data);

    nodeToInsert-> next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,int position) {

    //delete the first node
    if(position == 1) {

        Node* temp = head;
        head = head-> next;

        ///memory free start node
        temp-> next = NULL;
        delete temp;
    } else {

        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    // Node *node1 = new Node(15);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node *node1 = new Node(10);
    Node *head = node1;
    Node* tail = node1;
    // print(head);

    // insertAtHead(head, 15);
    // print(head);

    // insertAtHead(head, 20);
    // print(head);

    // insertAtHead(head, 25);
    // print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtTail(tail,25);
    print(head);

    insertAtTail(tail,10);
    print(head);

    insertAtPosition(head,tail,5,20);
    print(head);

    cout << "head " << head-> data << endl;
    cout << "tail " << tail-> data << endl;

    deleteNode(head,1);
    print(head);
}