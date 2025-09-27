#include <iostream>
#include <map>
#include<vector>
using namespace std;

//TC is O(n + n/2) = O(n)
//SC is O(n)

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

bool checkPalindrome(vector<int> &arr) {
    int n = arr.size();
    int s = 0, e = n - 1;

    while(s <= e) {
        if(arr[s] != arr[e]) {
            return false;
        }
        s++, e--;
    }
    return true;
}

bool isPalindrome(Node* head) {
    vector<int> arr;

    Node* temp = head;
    while(temp != NULL) {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(arr);
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