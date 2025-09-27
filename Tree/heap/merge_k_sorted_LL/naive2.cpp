#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *getMinNode(vector<Node *> &arr)
{
    Node *mini = NULL;
    int index = -1;

    // traverse all the k lists
    for (int i = 0; i < arr.size(); i++)
    {
        // if no node than continue
        if (arr[i] == NULL)
            continue;

        // if min node is found
        if (!mini || arr[i]->data < mini->data)
        {
            mini = arr[i];
            index = i;
        }
    }

    // increment the head ptr
    if (index != -1)
        arr[index] = arr[index]->next;

    return mini;
}

//! TC is O(n * k * k)
//! SC is O(1)

Node *mergeKLists(vector<Node *> &arr)
{
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    // find  the min node corressponding to all the k head nodes
    Node *mini = getMinNode(arr);

    // traverse all the lists and keep getting and attaching the min node
    while (mini)
    {
        tail->next = mini;
        tail = mini;

        mini = getMinNode(arr);
    }

    return dummy->next;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    int k = 3;

    vector<Node *> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node *head = mergeKLists(arr);

    printList(head);

    return 0;
}