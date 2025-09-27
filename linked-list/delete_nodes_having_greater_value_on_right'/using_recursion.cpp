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

//! TC is O(n)
//! SC is O(n)

Node *deleteNodesOnRightSide(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    //recursive call
    Node *nextNode = deleteNodesOnRightSide(head->next);

    // if right node's value is greater than
    // current node's value, then we can simply 
    // return the next node
    if (nextNode->data > head->data)
        return nextNode;

    //agar curr node ka value greater h tab usko nexrtNode k saath point se link krrdo and return the curr node
    head->next = nextNode;

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