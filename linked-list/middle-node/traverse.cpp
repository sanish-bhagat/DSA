#include<iostream>
using namespace std;

//TC is O(N)
//SC is O(1)

class Node{
    public:
        int data;
        Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &tail,int data) {

    //create a new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;

    while(head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}

Node* findMiddle(Node* &head) {
    int len = getLength(head);
    int ans = len / 2;

    Node* temp = head;
    int cnt = 0;

    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }

    return temp;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,12); 
    insertAtTail(tail,13);
    insertAtTail(tail,14);

    print(head);

    Node* res = findMiddle(head);
    cout << res -> data;
}