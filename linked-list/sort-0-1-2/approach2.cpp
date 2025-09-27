#include <iostream>
#include <map>
using namespace std;

// TC is O(n)
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
    // ~Node()
    // {
    //     int value = this->data;

    //     if (this->next != NULL)
    //     {
    //         // memory is free
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << "Memory is free for " << value << endl;
    // }
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
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtTail(Node *&tail, Node* curr)
{
    tail->next = curr;
    tail = curr;
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

Node* sort012(Node* head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //create separate list 0s, 1s and 2s
    while(curr != NULL) {

        int value = curr -> data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        } else if(value == 1) {
            insertAtTail(oneTail, curr);
        } else if(value == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    //merge the sublist

    //1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    } else {
        //1s list is empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead -> next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

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