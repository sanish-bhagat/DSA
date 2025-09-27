#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//! TC is O(n*logn)
//! SC is O(logn)

Node *findMiddle(Node *head) {

    Node *slow = head;
    Node *fast = head -> next;  //as we have to find the first middle value

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node *mergeTwoLists(Node *list1, Node *list2) {

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while(list1 != NULL && list2 != NULL) {

        if(list1 -> data < list2 -> data) {
            temp -> next = list1;
            temp = list1;
            list1 = list1 -> next;
        }
        else {
            temp -> next = list2;
            temp = list2;
            list2 = list2 -> next;
        }
    }

    //agar koi bhi list mein still koi node present h toh usko insert krrdo
    if(list1)
        temp -> next = list1;
    else    
        temp -> next = list2;

    return dummy -> next;
}

Node *MergeSort(Node *head) {

   //base case
   if(head == NULL || head -> next == NULL)
        return head;

    Node *middle = findMiddle(head);
    
    //slpit list into two halves
    Node *rightHead = middle -> next;

    //first half k last element k next ko NULL point krrdo
    middle -> next  = NULL;
    Node *leftHead = head;

    //recursive calls for each splitted lists
    leftHead = MergeSort(leftHead);
    rightHead = MergeSort(rightHead);

    //merge the splitted lists and return
    return mergeTwoLists(leftHead, rightHead);
}

int main() {
      
    // Create a hard-coded singly linked list:
    // 9 -> 8 -> 5 -> 2
    Node *head = new Node(9);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);

    head = MergeSort(head);
    printList(head);

    return 0;
}