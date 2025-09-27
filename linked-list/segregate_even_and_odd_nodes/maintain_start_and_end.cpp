#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

Node *segregateEvenOdd(Node *head) {
    //make dummy nodes for even and odd lists
    Node *eStart = new Node(0);
    Node *oStart = new Node(0);

    Node *eEnd = eStart;
    Node *oEnd = oStart;

    Node *curr = head;

    while(curr != NULL) {
        int val = curr -> data;

        //if value is even append it to the even list
        if(val % 2 == 0) {
            eEnd -> next = curr;
            eEnd = eEnd -> next;
        }

        //if value is odd append it to the odd list
        else {
            oEnd -> next = curr;
            oEnd = oEnd -> next;
        }

        curr = curr -> next;
    }

    //point the end of the odd list to NULL
    oEnd -> next = NULL;

    //link the even and odd list
    eEnd -> next = oStart -> next;

    Node *newHead = eStart -> next;

    //delete the dummy nodes
    delete(eStart);
    delete(oStart);

    return newHead;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    // Let us create a sample linked list as following
    // 0->1->4->6->9->10->11
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);

    cout << "Original Linked list: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "\nModified Linked list: ";
    printList(head);

    return 0;
}