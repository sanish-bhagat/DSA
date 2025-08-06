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

//! TC is O(n)
//! SC is O(n)

bool isPalindromeRec(Node *end, Node *&start) {

    //base case
    if(end == NULL)
        return true;

    //check for right half
    bool right = isPalindromeRec(end -> next, start);

    bool ans = right && start -> data == end -> data;

    start = start -> next;

    return ans;
}

bool isPalindrome(Node *head) {
    Node *start = head;
    
    return isPalindromeRec(head, start);
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