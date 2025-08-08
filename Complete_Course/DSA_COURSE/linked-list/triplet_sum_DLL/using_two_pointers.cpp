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

int countPairs(Node *start, Node *last, int value) {

    int cnt = 0;

    while(start != NULL && last != NULL && start != last && last -> next != start) {

        if((start -> data + last -> data) == value) {
            cnt++;
            start = start -> next;
            last = last -> prev;
        }

        else if((start -> data + last -> data) < value)
            start = start -> next;

        else
            last = last -> prev;
    }

    return cnt;
}

//! TC is O(n * n)
//! SC is O(1)

int countTriplets(Node *head, int x) {

    Node *curr, *first, *last;

    int count = 0;

    //point to the last node
    last = head;
    while(last -> next != NULL)
        last = last -> next;


    for(curr = head; curr != NULL; curr = curr -> next) {

        //point to the next = node of the current
        first = curr -> next;

        //find for the pair with sum = (x - curr node's value)
        count += countPairs(first, last, x - curr -> data);
    }

    return count;
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

    int x = 8;
    cout << countTriplets(head, x);
    return 0;
}