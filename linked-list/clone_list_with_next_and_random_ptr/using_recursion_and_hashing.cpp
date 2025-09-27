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

Node *cloneHelper(Node *head, unordered_map<Node*, Node*> &mp) {
    //base case
    if(head == NULL)
        return NULL;

    //node is already present in the map
    if(mp.find(head) != mp.end())
        return mp[head];

    //clone the curr node and store krrlo hash map mein
    Node *cloneNode = new Node(head -> data);
    mp[head] = cloneNode;

    //update the next and random ptr using recursive calls
    cloneNode -> next = cloneHelper(head -> next, mp);
    cloneNode -> random = cloneHelper(head -> random, mp);

    return cloneNode;
}

//! TC is O(n)
//! SC is O(3n)

Node *cloneLinkedList(Node *head) {
    unordered_map<Node*, Node*> mp;
    return cloneHelper(head, mp);
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