#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//! TC is O(n*logn)
//! SC is O(n)

Node *getTail(Node *head) {

    Node *curr = head;

    while(curr != NULL && curr -> next != NULL) {
        curr = curr -> next;
    }

    return curr;
}

Node *partition(Node *head, Node *tail) {

    //first nie ko pivot select krrlo
    Node *pivot = head;

    //pre and curr are used taaki nodes jo small h wo left side mein shift krr sake
    Node *pre = head, *curr = head;

    //traverse till curr reaches to next node of tail
    while(curr != tail -> next) {

        if(curr -> data < pivot -> data) {
            swap(curr -> data, pre -> next -> data);
            pre = pre -> next;
        }

        curr = curr -> next;
    }

    swap(pre -> data, pivot -> data);

    return pre;
}

void quickSortHelper(Node *head, Node *tail) {

    //base case
    if(head == NULL || head == tail)
        return;

    //pivot find krro
    Node *pivot = partition(head, tail);

    //recursive calls
    quickSortHelper(head, pivot); 

    quickSortHelper(pivot -> next, tail); 
}

Node *QuickSort(Node *head) {

    //get the last node of the list
    Node *tail = getTail(head);

    quickSortHelper(head, tail);

    return head;
}

int main() {
      
    // Create a hard-coded singly linked list:
    // 9 -> 8 -> 5 -> 2
    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);

    head = QuickSort(head);
    printList(head);

    return 0;
}