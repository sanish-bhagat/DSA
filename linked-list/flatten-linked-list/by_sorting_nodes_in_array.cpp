#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *bottom;

    Node(int newdata)
    {
        data = newdata;
        next = bottom = nullptr;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

//! TC is O(n * m * log(n * m))
//! SC is O(n * m)

Node *flatten(Node *root)
{
    vector<int> values;

    while (root != NULL)
    {
        values.push_back(root->data);

        Node *temp = root->bottom;
        while (temp != NULL)
        {
            values.push_back(temp->data);
            temp = temp->bottom;
        }

        root = root->next;
    }

    sort(values.begin(), values.end());

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < values.size(); i++)
    {
        Node *newNode = new Node(values[i]);

        if (head == NULL)
            head = newNode;
        else
            tail->bottom = newNode;

        tail = newNode;
    }

    return head;
}

int main()
{

    // Create a hard-coded linked list:
    //   5 -> 10 -> 19 -> 28
    //   |    |     |
    //   V    V     V
    //   7    20    22
    //   |          |
    //   V          V
    //   8          50
    //   |
    //   V
    //   30

    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    head = flatten(head);

    printList(head);
    return 0;
}