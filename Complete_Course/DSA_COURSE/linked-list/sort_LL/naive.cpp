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

//! TC is O(2*n + n*logn)
//! SC is O(n)

Node *MergeSort(Node *head) {

    vector<int> arr;
    Node *temp =head;

    while(temp != NULL) {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;

    while(temp != NULL) {
        temp -> data = arr[i];
        temp = temp -> next;
        i++;
    }

    return head;
}

int main() {
      
    // Create a hard-coded singly linked list:
    // 9 -> 8 -> 5 -> 2
    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);

    head = MergeSort(head);
    printList(head);

    return 0;
}