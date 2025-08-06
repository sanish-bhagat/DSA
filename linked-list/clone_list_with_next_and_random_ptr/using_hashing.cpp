#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
  
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

//! TC is O(2n)
//! SC is O(2n)

Node *cloneLinkedList(Node *head) {

    unordered_map<Node *, Node*> mp;
    Node *curr = head;

    //map the new nodes with their corresponding nodes
    while(curr != NULL) {
        mp[curr] = new Node(curr -> data);
        curr = curr -> next;
    }

    curr = head;

    //update the next and random pointer of the new nodes
    while(curr != NULL) {
        mp[curr] -> next = mp[curr -> next];
        mp[curr] -> random = mp[curr -> random];
        curr = curr -> next;
    }

    //return the head of the cloned list
    return mp[head];
}


// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
      	if(head->random)
          	cout << head->random->data << ")";
      	else 
          	cout << "null" << ")";
        
      	if(head->next != NULL)
          	cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
  
    // Print the original list
    cout << "Original linked list:\n";
    printList(head);
  
    // Function call
    Node* clonedList = cloneLinkedList(head);
  
    cout << "Cloned linked list:\n";
    printList(clonedList);
  
    return 0;
}