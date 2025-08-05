#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

//! TC is O(n)
//! Sc is O(1)

Node *moveToFront(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    Node *last = head, *slast = NULL;

    // traverse till last node
    while (last->next != NULL)
    {
        slast = last;
        last = last->next;
    }

    // slast ko last node bna do
    slast->next = NULL;

    // curr head ko 2nd node
    last->next = head;

    // last node ko new head bna do
    head = last;

    return head;
}

int main()
{
    // Create a linked list 1->2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked list before: " << endl;
    printList(head);

    head = moveToFront(head);

    cout << "Linked list after: " << endl;
    printList(head);
}