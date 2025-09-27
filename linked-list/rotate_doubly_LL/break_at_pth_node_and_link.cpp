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

//! TC is O(n)
//! SC is O(1)

Node *rotateDLL(Node *head, int p) {

    if(!head || !head -> next || p == 0)
        return head;

    int len = 0;
    Node *temp = head;

    //find the length of the  list
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    //avoid unnecessary computations
    p = p % len;
    if(p == 0)
        return head;

    Node *curr = head;

    //find the node at pth position
    for(int i = 1; i<p; i++) 
        curr = curr -> next;

    Node *newHead = curr ->next;
    curr -> next = NULL;
    newHead -> prev = NULL;

    Node *tail = newHead;

    while(tail -> next != NULL)
        tail = tail -> next;

    //link the old tail node and old head node to the list
    tail -> next = head;
    head -> prev = tail;

    return newHead;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    int p = 3;
    head = rotateDLL(head, p);
    printList(head);

    return 0;
}