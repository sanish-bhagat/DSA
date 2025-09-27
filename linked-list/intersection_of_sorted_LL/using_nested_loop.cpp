#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

//! TC is O(m * n)
//! SC is O(min(m, n))

Node *findIntersection(Node *head1, Node *head2) {

    Node *res = NULL, *temp = NULL;

    for(Node *ptr1 = head1; ptr1 != NULL; ptr1 = ptr1 -> next) {

        for(Node *ptr2 = head2; ptr2 != NULL; ptr2 = ptr2 -> next) {

            if(ptr1 -> data == ptr2 -> data) {

                if(!res) {
                    res = new Node(ptr1 -> data);
                    temp = res;
                }
                else {
                    temp ->next = new Node(ptr1 -> data);
                    temp = temp -> next;
                }

                break; // as ll is sorted
            }
        }
    }

    return res;
}

int main()
{
    // Create the first linked list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    // Create the second linked list
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    // Find the intersection of the two linked lists
    Node* result = findIntersection(head1, head2);

    // Print the intersection list
    while (result) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}