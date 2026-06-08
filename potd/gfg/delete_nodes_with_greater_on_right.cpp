#include <iostream>
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

// Traverses the list in recursive manner
Node *compute(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *nextNode = compute(head->next);

    if (nextNode->data > head->data)
    {
        delete (head);
        return nextNode;
    }

    head->next = nextNode;

    return head;
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

int main()
{

    Node *head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    head = compute(head); // updated call

    printList(head);

    return 0;
}