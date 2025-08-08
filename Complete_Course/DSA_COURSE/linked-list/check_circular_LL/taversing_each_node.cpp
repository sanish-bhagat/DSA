#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//! TC is O(n)
//! SC is O(1)

bool isCircular(Node *head) {

    if(head == NULL)
        return false;

    Node *curr = head -> next;

    while(curr && curr != head)
        curr = curr -> next;

    return (curr == head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
