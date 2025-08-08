// C++ program to merge K sorted linked lists
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

// custom class for min heap
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

//! TC is O(n * k * logk) or O(n * logk) -> for equal sized list
//! SC is O(log k)

Node *mergeKLists(vector<Node *> &arr)
{
    // min heap
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *dummy = new Node(-1);
    Node *tail = dummy;

    // push the first node(head node) of every sorted list
    for (auto head : arr)
        pq.push(head);

    // process all the nodes
    while (!pq.empty())
    {
        // pop the min node
        Node *top = pq.top();
        pq.pop();

        // link the top of the pq to the res list
        tail->next = top;
        tail = top;

        // if top's next exist then push it into the pq
        if (top->next)
            pq.push(top->next);
    }

    // return the head of the res list
    return dummy->next;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    int k = 3;

    vector<Node *> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node *head = mergeKLists(arr);

    printList(head);

    return 0;
}