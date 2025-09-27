#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

//! TC is O(2n)
//! SC is O(n)

Node *reverse(Node *head) {

    stack<int> st;
    Node *temp = head;

    while(temp != NULL) {
        st.push(temp -> data);
        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }

    return head;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
  
    // Create a hard-coded doubly linked list:
    // 1 <-> 2 <-> 3 <-> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original Linked list" << endl;
    printList(head);
    head = reverse(head);
    cout << "\nReversed Linked list" << endl;
    printList(head);

    return 0;
}