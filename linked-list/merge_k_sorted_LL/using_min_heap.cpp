#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

class compare{
    public:
        bool operator()(Node *a, Node* b) {
            return a -> data > b -> data;
        }
};

//! TC is O(n * k * logk)
//! SC is O(log k)

Node *mergeKLists(vector<Node*> &arr) {

    Node *dummy = new Node(-1);
    Node *tail = dummy;

    priority_queue<Node*, vector<Node*>, compare> pq;

    //sab lists k head ko heap mein push krrdo
    for(Node *head : arr) {
        if(head != NULL)
            pq.push(head);
    }

    while(!pq.empty()) {
        //smallest element nikalo
        Node *top = pq.top();
        pq.pop();

        //resultant list mein append krrwado
        tail -> next = top;
        tail = tail -> next;

        //agar top ka next node exist krrta h toh usko heap mein push krrdo
        if(top -> next != NULL)
            pq.push(top -> next);
    }

    return dummy -> next;
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}