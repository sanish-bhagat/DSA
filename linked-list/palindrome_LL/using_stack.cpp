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

bool isPalindrome(Node *head) {

    Node *curr = head;
    stack<int> st;

    while(curr != NULL) {
        st.push(curr -> data);
        curr = curr -> next;
    }

    curr = head;

    while(curr != NULL) {
        int c = st.top();
        st.pop();

        if(curr -> data != c)
            return false;

        curr = curr -> next;
    }

    return true;
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