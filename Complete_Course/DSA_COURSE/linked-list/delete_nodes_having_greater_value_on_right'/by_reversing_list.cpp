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

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

Node *reverseList(Node *head)
{
    Node *prev = NULL, *next = NULL, *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *deleteNodes(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *maxNode = head, *curr = head, *temp = NULL;

    while (curr != NULL && curr->next != NULL)
    {

        // if curr is smaller than max, delete curr
        if (curr->next->data < maxNode->data)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }

        // curr is greter than max, then move curr ptr and update max to curr
        else
        {
            curr = curr->next;
            maxNode = curr;
        }
    }

    return head;
}

//! TC is O(n)
//! SC is O(1)

Node *deleteNodesOnRightSide(Node *head)
{

    // reverse the given list
    head = reverseList(head);

    // in the reversed list, delete the nodes having lesser value in right side
    head = deleteNodes(head);

    // reverse the list again
    head = reverseList(head);

    return head;
}

int main()
{

    // Create linked list
    // 12->15->10->11->5->6->2->3
    Node *head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    head = deleteNodesOnRightSide(head);

    printList(head);

    return 0;
}