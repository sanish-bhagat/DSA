#include <bits/stdc++.h>
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

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

//! TC is O(n * logk)
//! SC is O(k)

Node *sortAKSortedDLL(Node *head, int k)
{

    if (head == NULL)
        return head;

    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newHead = NULL, *last = NULL;

    for (int i = 0; head != NULL && i < k + 1; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {

        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return newHead;
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