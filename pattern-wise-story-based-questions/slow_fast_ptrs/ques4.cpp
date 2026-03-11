// In a distributed blockchain network, nodes are connected in a chain.

// Due to corruption, a node's pointer may accidentally point back to a previous node, creating a loop.

// Detect:

// Which node starts the loop?

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

ListNode *startOfCycle(ListNode *head)
{
    // slow moves 1-step and fast moves 2-step forward
    ListNode *slow = head, *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;

        // cycle detects -> find the start of the cycle
        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            // return the start of the cycle
            return slow;
        }
    } while (slow != fast);

    return slow;
}

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next = head->next;

    ListNode *start = startOfCycle(head);
    cout << start->val;
}