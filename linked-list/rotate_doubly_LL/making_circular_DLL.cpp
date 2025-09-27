#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

//! TC is O(n)
//! SC is O(1)

Node *rotateDLL(Node *head, int p) {

    if(head == NULL || head -> next == NULL)
        return head;

    Node *tail = head;

    while(tail -> next != NULL)
        tail = tail -> next;

    //make the DLL circular
    tail -> next = head;
    head -> prev = tail;

    for(int i = 1; i<=p; i++) {
        head = head -> next;
        tail = tail -> next;
    }

    //break krrrdo circular connection
    tail -> next = NULL;
    head -> prev = NULL;

    return head;
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    printList(head);

    int p = 3;
    head = rotateDLL(head, p);
    printList(head);

    return 0;
}