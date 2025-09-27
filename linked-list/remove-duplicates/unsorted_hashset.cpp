#include <bits/stdc++.h>
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
    // ~Node() {
    //     int value = this-> data;

    //     if(this-> next != NULL) {
    //         //memory is free
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << "Memory is free for " << value << endl;
    // }
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
//! Sc is O(n)

Node* uniqueUnsortedList(Node* head) {

    unordered_set<int> st;
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {

        //dulicate node
        if(st.find(curr -> data) != st.end()) {

            //adjust the pointers to skip the current one
            prev -> next = curr -> next;

            Node *temp = curr;
            curr = curr -> next;
            delete temp;
        }

        else {

            st.insert(curr -> data);
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,12);
    insertAtTail(tail,11);
    insertAtTail(tail,13);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);

    print(head);    

    // head = uniqueSortedList(head);
    // print(head);

    head = uniqueUnsortedList(head);

    print(head);
}