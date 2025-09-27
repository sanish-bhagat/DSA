#include <iostream>
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

//! TC is O(m * n)
//! SC is O(1)

Node *intersectPoint(Node *head1, Node *head2) {

    //iterate through 2nd list and check every node in the 1st list
    while(head2 != NULL){

        Node *temp = head1;

        while(temp) {
            if(temp == head2)
                return temp;
            temp = temp -> next;
        }

        head2 = head2 -> next;
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