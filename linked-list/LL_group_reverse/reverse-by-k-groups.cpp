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

Node* kReverse(Node* head, int k) {

    //base case
    if(head == NULL) {
        return NULL;
    }

    //step 1: reverse k nodes

    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    //Apply krro jab question mein diya ho ki jab tak 'k' nodes na ho tab tak reverse na krrna ho toh check k liye ek loop chlao

    // //Check if there are at least 'k' nodes to reverse
    // Node* check = head;
    // for(int i=0; i<k; i++) {
    //     if(!check) {
    //         return head; //Less than 'k' nodes return as it is
    //     }
    //     check = check -> next;
    // }

    while(curr != NULL && cnt < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    //step 2: recursive call
    if(forward != NULL) {
        head -> next = kReverse(forward,k);
    }

    //step 3: return head of reversed list
    return prev;
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