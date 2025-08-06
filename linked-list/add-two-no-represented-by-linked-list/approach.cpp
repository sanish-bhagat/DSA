#include <iostream>
#include <map>
using namespace std;

// TC is O(N + M)
// SC is O(max(N,M))

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

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    //empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *add(Node *first, Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{

    // step1 - reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step2 - add 2 LL
    Node *ans = add(first, second);

    // step3
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node *node1 = new Node(5);
    Node *head1 = node1;
    Node *tail1 = node1;

    Node *node2 = new Node(3);
    Node *head2 = node2;
    Node *tail2 = node2;

    insertAtTail(tail1, 4);
    // insertAtTail(tail1, 12);
    // insertAtTail(tail1, 13);
    // insertAtTail(tail1, 14);
    // insertAtTail(tail1, 15);
    print(head1);

    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);
    // insertAtTail(tail2, 4);
    // insertAtTail(tail2, 5);
    // insertAtTail(tail2, 12);
    print(head2);

    head1 = addTwoLists(node1, node2);
    print(head1);
}