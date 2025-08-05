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

bool detectLoop(Node* head) {

    if(head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp -> data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
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

    if(detectLoop(head)) {
        cout << "Cycle is present" << endl;
    } else {
        cout << "Cycle is not present" << endl;
    }

    

}