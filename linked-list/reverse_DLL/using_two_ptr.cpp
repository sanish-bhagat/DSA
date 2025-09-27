#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

//! TC is O(n)
//! SC is O(1)

Node *reverse(Node *head) {

    //base case
    if(head == NULL || head -> next == NULL)
        return head;

    Node *curr = head;
    Node *prevNode = NULL;

    //swap the pointers
    while(curr != NULL) {
        prevNode = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = prevNode;
        curr = curr -> prev;
    }

    return prevNode -> prev; 
}

int main() {
  
    // Create a hard-coded doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Linked list" << endl;
    printList(head);
    head = reverse(head);
    cout << "\nReversed Linked list" << endl;
    printList(head);

    return 0;
}