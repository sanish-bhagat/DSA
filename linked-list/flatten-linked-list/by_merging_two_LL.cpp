#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *bottom;

    Node(int newdata) {
        data = newdata;
        next = bottom = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

Node *merge(Node *head1, Node *head2) {

    Node *dummy = new Node(-1);

    Node *tail = dummy;

    while(head1 && head2) {
        if(head1 -> data <= head2 -> data) {
            tail -> bottom = head1;
            head1 = head1 -> bottom; 
        }
        else {
            tail -> bottom = head2;
            head2 = head2 -> bottom;
        }

        tail = tail -> bottom;
    }

    //append the remaining nodes
    if(!head1)
        tail -> bottom = head2;
    else
        tail -> bottom = head1;

    return dummy -> bottom;
}

//! TC is O(n * n * m)
//! SC is O(n)

Node *flatten(Node *root) {

    //base case
    if(root == NULL || root -> next == NULL)
        return root;

    //recursive call for next sub-LL
    root -> next = flatten(root -> next);

    //merge the lists
    root = merge(root, root -> next);

    return root;
}

int main() {

    // Create a hard-coded linked list:
    //   5 -> 10 -> 19 -> 28
    //   |    |     |
    //   V    V     V
    //   7    20    22
    //   |          |
    //   V          V
    //   8          50
    //   |
    //   V
    //   30

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flatten(head);

    printList(head);
    return 0;
}