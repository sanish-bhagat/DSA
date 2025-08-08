#include <bits/stdc++.h>
using namespace std;

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

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

//! TC is O(n*k log k)
//!  SC is O(K)
Node *mergeKLists(vector<Node *> &arr)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = arr.size();

    if (k == 0)
        return NULL;

    // step 1 - build minHeap for the first row elements
    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        // answer LL is empty
        if (head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            // insert at LL
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

int main()
{
}