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

Node *reverseKNodes(Node *head, int k) {
    int count = 0;
    Node *curr = head, *next = NULL, *prev = NULL;

    while(curr && count < k) {
        next = curr -> next;
        curr -> next = prev;
        curr -> prev = NULL;

        if(prev != NULL) {
            prev -> prev = curr;
        }

        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

//! TC is O(n)
//! SC is O(n)

Node *reverseKGroup(Node *head, int k) {

    if(head == NULL) 
        return head;

    Node *temp = head;
    int count = 0;

    //point temp to other group
    while(temp && count < k) {
        temp = temp -> next;
        count++;
    }

    Node *groupHead = NULL;
    Node *newHead = NULL;

    //reverse first k group
    groupHead = reverseKNodes(head, k);

    if(newHead == NULL)
        newHead = groupHead;

    //recursive call
    head -> next = reverseKGroup(temp, k);
    if(head -> next != NULL) {
        head -> next -> prev = head;
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