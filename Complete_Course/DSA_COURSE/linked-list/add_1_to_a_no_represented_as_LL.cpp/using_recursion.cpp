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

//! Tc is O(n)
//! Sc is O(n)

int addRec(Node *temp)
{
    // last node h toh usme 1 add krrdo
    if (temp == NULL)
        return 1;

    int carry = addRec(temp->next);

    // backtracking krrte time add krro
    temp->data += carry;

    if (temp->data < 10)
        return 0;

    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry = addRec(head);

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

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