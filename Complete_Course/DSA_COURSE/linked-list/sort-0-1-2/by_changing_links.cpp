#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a new node with data
    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << " " << node->data;
        node = node->next;
    }
    cout << "\n";
}

//! TC is O(n)
//! SC is O(1)

Node *sortList(Node *head)
{
    if (!head || !head->next)
        return head;

    // make three dummy nodes
    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);

    // point three ptr on the dummy nodes
    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node *curr = head;
    while (curr != NULL)
    {

        // if data is 0 then append it to ptr zero, and update zero
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        // if data is 1 then append it to ptr one, and update one
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        // if data is 2 then append it to ptr two, and update two
        else
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // update head
    head = zeroD->next;

    // connect the three lists
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    // delete the dummy nodes
    delete zeroD;
    delete one;
    delete twoD;

    return head;
}

// Driver code
int main()
{

    // Create a hard-coded linked list:
    // 1 -> 1 -> 2 -> 1 -> 0 -> NULL
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printList(head);

    // Function to sort the linked list
    head = sortList(head);

    cout << "Linked List after Sorting:";
    printList(head);

    return 0;
}