// A fitness app tracks runners on a circular running track.

// Each runner's step points to the next runner ahead of them. Because the track is circular, sometimes the pointers eventually loop back to a previous runner.

// You are given the head of the runner list.

// Determine whether the running sequence eventually forms a cycle.

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

bool isCycle(ListNode *head)
{
    // slow moves 1 step and fast moves 2step forward
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;

        // slow and fast meets -> cycle exists
        if (slow == fast)
            return true;
    }

    // cycle doesn't exist
    return false;
}

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next = head->next;

    ListNode *curr = head;

    if (isCycle(head))
        cout << "true";

    else
        cout << "false";
}