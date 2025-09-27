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

//! TC is O(m + n)
//! SC is O(1)

Node *intersectPoint(Node *head1, Node *head2)
{

    Node *p1 = head1, *p2 = head2;

    if (p1 == NULL || p2 == NULL)
        return NULL;

    while (p1 != p2)
    {
        // Move to the next node in each list and if the one
        // pointer reaches NULL, start from the other linked list
        p1 = p1 ? p1->next : head2;
        p2 = p2 ? p2->next : head1;
    }
    
    // Return the intersection node, or nullptr if no intersection
    return p1;
}

int main()
{

    // creation of first list: 10 -> 15 -> 30
    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    // creation of second list: 3 -> 6 -> 9 -> 15 -> 30
    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);

    // 15 is the intersection point
    head2->next->next->next = head1->next;

    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}