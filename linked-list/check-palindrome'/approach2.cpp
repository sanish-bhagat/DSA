#include <iostream>
#include <map>
#include<vector>
using namespace std;

//TC is O(n)
//SC is O(1)

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node() {
        int value = this-> data;

        if(this-> next != NULL) {
            //memory is free
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertAtHead(Node* &head, int data) {

    //create a new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data) {

    //create a new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << " List is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(head -> next == NULL) {
        return true;
    }

    //step1 -> find middle
    Node* middle = getMid(head);

    //step2 -> reverse list after middle
    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    //step3 -> compare both halves
    Node* head1 = head;
    Node* head2 = middle -> next;

    while(head2 != NULL) {

        if(head1 -> data != head2 -> data) {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //step4 -> repeat step 2
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,2);
    insertAtTail(tail,1);

    print(head);

    if(isPalindrome(head)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
}