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

//! TC is O(n * n)
//! Sc is O(n)

int countTriplets(Node *head, int x) {
    unordered_map<int, Node*> mpp;

    int cnt = 0;

    //mapping of each value to its node ptr
    for(Node *ptr = head; ptr != NULL; ptr = ptr -> next)
        mpp[ptr->data] = ptr;

    for(Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1 -> next) {

        for(Node *ptr2 = ptr1 -> next; ptr2 != NULL; ptr2 = ptr2 -> next) {

            int sum = ptr1 -> data + ptr2 -> data;

            if(mpp.find(x - sum) != mpp.end() && mpp[x-sum] != ptr1 && mpp[x-sum] != ptr2)
                cnt++;
        }
    }

    //cnt / 3 as each triplet is counted three times
    return cnt/3;
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