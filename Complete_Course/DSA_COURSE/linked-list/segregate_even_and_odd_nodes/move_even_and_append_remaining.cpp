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

    //to traverse the original LL
    Node *curr = head, *prev = NULL;

    //res list
    Node *resStart = NULL, *resEnd = NULL;

    while(curr != NULL) {

        //if the curr node's value is even then add it to the res list
        if(curr -> data % 2 == 0) {

            //remove the curr node from the original list
            if(prev != NULL) {
                prev -> next = curr -> next;
            }
            else {
                //if the curr node is head
                head = curr -> next;
            }

            if(resStart == NULL) {
                resStart = curr;
                resEnd = curr;
            }
            else {
                resEnd -> next = curr;
                resEnd = resEnd -> next;
            }

            curr = curr -> next;
        }
        //if the curr node's value is odd
        else {
            prev = curr;
            curr = curr -> next;
        }
    }

    //if res list is NULL(means no even nodes) then simply return head(containing odd nodes)
    if(resStart == NULL)
        return head;

    //link the even node list to the odd node list
    resEnd -> next = head;

    return resStart;
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