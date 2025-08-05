#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { 
        data = d; 
        next = nullptr;
    }
};

Node *reverse(Node *head) {

    Node *prev = NULL, *curr = head, *next = NULL;

    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isIdentical(Node *n1, Node *n2) {

    while(n1 != NULL && n2 != NULL) {

        if(n1 -> data != n2 -> data)
            return 0;
    
        n1 = n1 -> next;
        n2 = n2 -> next;
    }

    return 1;
}

//! TC is O(n)
//! SC is O(1)

bool isPalindrome(Node *head) {

    if(head == NULL || head -> next == NULL)
        return true;

    Node *slow = head, *fast = head;

    while(fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node *head2 = reverse(slow -> next);
    slow -> next = NULL;

    bool res = isIdentical(head, head2);

    head = reverse(head2);
    slow -> next = head2;

    return res;
}

int main() {
  
    // Linked list : 1->2->3->2->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    bool result = isPalindrome(head);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}