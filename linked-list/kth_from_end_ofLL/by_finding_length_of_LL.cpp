
#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node {
    int data;
    Node* next;
	
  	// Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

int cntNodes(Node *head) {
    int len = 0;

    Node *curr = head;

    while(curr != NULL) {
        len++;
        curr = curr -> next;
    }

    return len;
}

//! TC is O(n)
//! SC is O(1)

int findNthFromLast(Node *head, int k) {
    int length = cntNodes(head);

    int req = length - k + 1;

    Node *curr = head;
    int cnt = 1;

    while(cnt < req) {
        cnt++;
        curr = curr -> next;
    }

    return curr -> data;
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