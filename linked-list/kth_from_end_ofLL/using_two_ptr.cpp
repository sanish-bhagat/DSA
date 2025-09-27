#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize a new node with data
    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

int findNthFromLast(Node *head, int k) {
    Node *refPtr = head, *mainPtr = head;

    //move the refPtr to the kth node from the begining
    for(int i = 1; i<k; i++) {
        refPtr = refPtr -> next;

        //if k > len of LL then return -1
        if(refPtr == NULL)
            return -1;
    }

    //now traverse the LL until refPtr does not reach the last node of the LL
    //keeping a dist of (k - 1) between refPtr and mainPtr
    while(refPtr -> next != NULL) {
        refPtr = refPtr -> next;
        mainPtr = mainPtr -> next;
    }

    return mainPtr -> data;
}

int main() {
  
    // Create a hard-coded linked list:
    // 35 -> 15 -> 4 -> 20
    Node* head = new Node(35);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    // Function Call to find the 4th node from end
    cout << findNthFromLast(head, 4);
    return 0;
}