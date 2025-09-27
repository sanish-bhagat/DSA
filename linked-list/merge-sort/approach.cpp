#include <iostream>
#include <map>
using namespace std;

//TC is O(n logn)
//SC is O(logn)

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
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge two sorted linked list
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;
}

Node* mergeSort(Node* &head) {

    //bae case
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    //break linked list into 2 halves, after finding mid
    Node* mid = getMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive calls to sort both halves;
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halves
    Node* result = merge(left, right);

    return result;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,12);
    insertAtTail(tail,11);
    insertAtTail(tail,14);
    insertAtTail(tail,13);
    insertAtTail(tail,15);

    print(head);

    head = mergeSort(head);
    print(head);
}