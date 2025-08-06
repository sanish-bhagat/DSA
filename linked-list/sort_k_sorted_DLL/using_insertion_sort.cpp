#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

//! TC is O(n * k)
//! SC is O(1)

Node *sortAKSortedDLL(Node *head, int k)
{

    Node *node = head->next;

    while (node != NULL)
    {

        Node *curr = node;
        Node *next = node->next;

        while (curr->prev != NULL && curr->data < curr->prev->data)
        {

            Node *node1 = curr->prev->prev;
            Node *node2 = curr->prev;
            Node *node3 = curr->next;

            if (node1 != NULL)
                node1->next = curr;

            curr->prev = node1;
            node2->next = node3;

            if (node3 != NULL)
                node3->prev = node2;

            curr->next = node2;
            node2->prev = curr;
        }

        if (curr->prev == NULL)
            head = curr;

        node = next;
    }

    return head;
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    // Create the doubly linked list:
    // 3 <-> 2 <-> 1 <-> 5
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(1);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int k = 2;
    head = sortAKSortedDLL(head, k);
    printList(head);
    return 0;
}