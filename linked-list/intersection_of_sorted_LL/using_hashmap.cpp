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

//! TC is O(m + n)
//! Sc is O(m)

Node *findIntersection(Node *head1, Node *head2) {

    Node *dummy = new Node(0);
    Node *curr = dummy;

    unordered_map<int, int> set;

    while(head1 != NULL) {
        set[head1 -> data]++;
        head1 = head1 -> next;
    }

    while(head2 != NULL) {

        if(set.count(head2 -> data)) {
            set[head2 -> data]--;

            if(set[head2 -> data] == 0)
                set.erase(head2 -> data);

            curr -> next = new Node(head2 -> data);
            curr = curr -> next;
        }

        head2 = head2 -> next;
    }

    Node *res = dummy -> next;
    delete dummy;
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