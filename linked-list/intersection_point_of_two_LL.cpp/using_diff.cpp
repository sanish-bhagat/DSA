//? using diff in node count

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

int countNodes(Node *head) {
    int cnt = 0;
    while(head != NULL) {
        cnt++;
        head = head -> next;
    }

    return cnt;
}

Node *getIntersectionByDiff(int diff, Node *head1, Node *head2) {

    Node *curr1 = head1, *curr2 = head2;

    for(int i = 0; i<diff; i++) {
        if(curr1 == NULL)
            return NULL;
        curr1 = curr1 -> next;
    }

    while(curr1 != NULL && curr2 != NULL) {
        if(curr1 == curr2)
            return curr1;

        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }

    return NULL;
}

//! TC is O(m + n)
//! SC is O(1)

Node *intersectPoint(Node *head1, Node *head2) {

    int len1 = countNodes(head1);
    int len2 = countNodes(head2);

    int diff = 0;

    if(len1 > len2) {
        diff = len1 - len2;
        return getIntersectionByDiff(diff, head1, head2);
    }
    else {
        diff = len2 - len1;
        return getIntersectionByDiff(diff, head2, head1);
    }
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