// A distributed system stores logs across servers arranged in a linked chain.

// To rebalance load, the system must find the middle server of the chain.

// You are given the head of the linked list of servers.

// Return the middle node.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

ListNode* middleNode(ListNode* head) {

    // slow moves 1-step and fast moves 2-step forward
    ListNode *slow = head, *fast = head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // slow points to mid node of the LL
    return slow;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    ListNode *mid = middleNode(head);
    cout << mid -> val;
}