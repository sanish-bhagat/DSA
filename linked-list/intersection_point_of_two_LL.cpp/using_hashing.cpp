#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

//! TC is O(m + n)
//! SC is O(m)

Node *intersectPoint(Node *head1, Node *head2) {

    unordered_set<Node *> st;

    Node *curr1 = head1;
    while(curr1 != NULL) {
        st.insert(curr1);
        curr1 = curr1 -> next;    
    }

    Node *curr2 = head2;
    while(curr2 != NULL) {
        if(st.find(curr2) != st.end())
            return curr2;

        curr2 = curr2 -> next;
    }

    return NULL;
}

int main() {
    
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