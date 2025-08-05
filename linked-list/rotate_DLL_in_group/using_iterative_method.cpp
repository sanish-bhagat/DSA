#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//! TC is O(n)
//! SC is O(1)

Node *reverseKGroup(Node *head, int k) {

    if(head == NULL)
        return head;

    Node *curr = head, *newHead = NULL, *tail = NULL;

    while(curr != NULL) {

        Node *groupHead = curr;
        Node *prev = NULL, *next = NULL;
        int count = 0;

        //reverse nodes in current grp
        while(curr && count < k) {
            next = curr -> next;
            curr-> next = prev;
            curr -> prev = prev;

            if(prev != NULL)
                prev -> prev = curr;

            prev = curr;
            curr = next;
            count++;
        }

        // if newHead is NULL, point it to the head of the reversed grp
        if(newHead == NULL)
            newHead = prev;

        //connect prev grp to curr reversed grp
        if(tail != NULL) {
            tail -> next = prev;
            prev -> prev = tail;
        }

        tail = groupHead;
    }

    return newHead;
}

int main() {
  
    // Creating a sample doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head = reverseKGroup(head, 2);
    printList(head);

    return 0;
}