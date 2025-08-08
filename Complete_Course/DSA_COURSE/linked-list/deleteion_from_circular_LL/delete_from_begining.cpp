#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void printList(Node* last) {
    if(last == NULL) return ;
 
    Node *head = last->next;
    while (true){
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

//! TC is O(1)
//! SC is O(1)

Node *deleteFirstNode(Node *last) {
    if(last == NULL)
        return NULL;
    
    Node *head = last -> next;

    //if only one node is present in the linked list
    if(head == last) {
        last = NULL;
        delete(head);
    }
    else {
        last -> next = head -> next;
        delete head;
    }

    return last;
}

int main() {
    // Create circular linked list: 2, 3, 4
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    // Delete the first node
    last = deleteFirstNode(last);

    cout << "List after deleting first node: ";
    printList(last);

    return 0;
}