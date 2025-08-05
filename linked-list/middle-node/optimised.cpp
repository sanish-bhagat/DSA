#include <iostream>
using namespace std;

// TC is O(N)
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
};

void insertAtTail(Node *&tail, int data)
{

    // create a new node
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{

    if (head == NULL)
    {
        cout << "List is empty" << endl;
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

Node *getMiddle(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    // 2 Nodes
    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);

    print(head);

    Node *res = getMiddle(head);
    cout << res->data;
}