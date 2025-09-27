#include <iostream>
#include <map>
using namespace std;

// TC is O(n)
// SC is O(1)

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            // memory is free
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    // create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{

    // create a new node
    Node *temp = new Node(data);
    tail->next = temp;
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

Node *solve(Node *first, Node *second)
{

    //if only one element is present in 1st list
    if(first -> next == NULL) {
        first -> next = second;
        return first; 
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            // add node in between the second list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // curr1 and next1 ko aage badhana h
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *sortTwoLists(Node *first, Node *second)
{

    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head1 = node1;
    Node *tail1 = node1;

    Node* node2 = new Node(0);
    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail1, 11);
    // insertAtTail(tail1, 12);
    insertAtTail(tail1, 13);
    insertAtTail(tail1, 14);
    insertAtTail(tail1, 15);
    print(head1);


    insertAtTail(tail2, 1);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 12);
    print(head2);

    head1 = sortTwoLists(node1, node2);
    print(head1);
}