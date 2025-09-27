#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node *head)
{

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *reverse(Node *head)
{
    Node *curr = head, *prev = NULL, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//! Tc is O(3n)
//! Sc is O(1)

Node *addOne(Node *head)
{
    // reverse the given list
    head = reverse(head);

    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data += carry;

        // temp -> data + 0 = temp -> data hi hoga to faltu aage traverse krr k koi fayda nhi h
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }

        else
        {
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    // new node bnana hoga aur usko reversed list ka new head bna do
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;
}

int main()
{
    // Create a hard-coded linked list:
    // 1 -> 9 -> 9 -> 9
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    head = addOne(head);

    printList(head);

    return 0;
}