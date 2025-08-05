#include <bits/stdc++.h> 
using namespace std;

// A linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
  	cout << "\n";
}

//! Tc is O(n * logn)
//! SC is O(n)

Node *sortList(Node *head) {
    if(!head || !head -> next)
        return head;

    vector<int> arr;

    Node *curr = head;
    while(curr != NULL) {
        arr.push_back(curr -> data);
        curr = curr -> next;
    }

    sort(arr.begin(), arr.end());

    Node *newHead = NULL, *tail = NULL;

    for(int i =0; i<arr.size(); i++) {
        Node *newNode = new Node(arr[i]);

        if(newHead == NULL) {
            newHead = tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = tail -> next;
        }
    }

    return newHead;
}

// Driver code
int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 1 -> 2 -> 1 -> 0 -> NULL 
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printList(head);

  	// Function to sort the linked list
    head = sortList(head);

    cout << "Linked List after Sorting:";
    printList(head);

    return 0;
}