#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

//! TC is O(n)
//! SC is O(1)

Node *reverseList(Node *head) {
    if(head == NULL)
        return NULL;

    Node *prev = NULL, *curr = head, *next = NULL;
    bool firstPass = true;  //to change the ptr of the first node, as curr will be pointing to head itself

    while(firstPass || curr != head) {
        firstPass = false;
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    } 

    //make the LL circular
    head -> next = prev;

    //update the head to the reversed list
    head = prev;
    return head;
}

//! TC is O(n)
//! SC is O(1)

Node *deleteNode(Node *head, int key) {
    if(head == NULL)
        return head;

    Node *prev = NULL, *curr = head;

    if(head -> data == key) {

        //only one node is present in CLL
        if(head -> next == head) {
            delete head;
            return NULL;
        }

        //get the last node
        Node *last = head;
        while(last -> next != head)
            last = last -> next;

        Node *temp = head;

        //point the head to the next node
        head = head -> next;
        //update next ptr of last
        last -> next = head;
        delete temp;
        return head;
    }

    prev = curr, curr = curr -> next;

    while(curr != head) {
        if(curr -> data == key) {
            prev -> next = curr -> next;
            delete curr;
            return head;
        }
        prev = curr, curr = curr -> next;
    }

    return head;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (true) {
        std::cout << temp->data << " ";
        temp = temp->next;
        if (temp == head) break;
    }
    std::cout << std::endl;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}

int main() {
    Node* head = nullptr;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    std::cout << "Original List: ";
    printList(head);

    head = deleteNode(head, 20);
    std::cout << "After Deletion (20): ";
    printList(head);

    head = reverseList(head);
    std::cout << "After Reversing: ";
    printList(head);

    return 0;
}
