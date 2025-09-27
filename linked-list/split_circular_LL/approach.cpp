#include <bits/stdc++.h>
using namespace std;

class Node { 
    public:
    int data; 
    Node *next; 
    Node (int new_value){
        data = new_value;
        next = nullptr;
    }
}; 

void printList(Node *head) { 
    Node *curr = head; 
    if(head != nullptr) { 
        do { 
        cout << curr->data << " "; 
        curr = curr->next; 
        } while(curr != head); 
          cout << endl; 
    } 
} 

//! TC is O(n)
//! SC is O(1)

pair<Node*, Node*> splitList(Node *head) {

    if(head == NULL)
        return {NULL, NULL};

    Node *slow = head, *fast = head;

    while(fast -> next != head && fast -> next -> next != head) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    if(fast -> next -> next == head)
        fast = fast -> next;

    Node *head1 = head, *head2 = slow -> next;

    fast -> next = slow -> next;

    slow -> next = head1;

    return {head1, head2};
}

int main() { 
    
    Node *head = new Node(1); 
    Node *head1 = nullptr; 
    Node *head2 = nullptr; 

    // Created linked list will be 1->2->3->4
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    pair<Node*, Node*> result = splitList(head); 
    head1 = result.first;
    head2 = result.second;
    
    printList(head1); 
    printList(head2);
    
    return 0; 
} 