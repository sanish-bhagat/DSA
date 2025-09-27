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
//! SC is O(k)
Node* kReverse(Node* head, int k) {

    //base case
    if(head == NULL || k <= 1)
        return head;

    stack<Node *> st;
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {

        int count = 0;

        //k nodes stack mein push krrdo
        while(curr != NULL && count < k) {
            st.push(curr);
            curr = curr -> next;
            count++;
        }

        while(!st.empty()) {
            //agar prev NULL pr point krr rha h toh usko st.top() pr point krrdo and head ko prev pr taaki hm last mein head return krrne paye
            if(prev == NULL) {
                prev = st.top();
                head = prev;
                st.pop();
            }
            else {
                prev -> next = st.top();
                prev = prev -> next;
                st.pop();
            }
        }
    }

    //last node k next pointer ko NULL krrdo
    prev -> next = NULL;

    return head;
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