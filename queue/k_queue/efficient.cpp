#include <bits/stdc++.h>
using namespace std;

class KQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int freeIndex;

public:
    KQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];

        // front to store the front element index of each queues
        front = new int[k];

        // rear to store the end index of the queue
        rear = new int[k];

        // next to store the next element index of each element
        next = new int[n];

        // to get the free spot
        freeIndex = 0;

        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
        }
    }

    bool isFull()
    {
        return freeIndex == -1;
    }

    bool isEmpty(int m)
    {
        return front[m] == -1;
    }

    void enqueue(int data, int m)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }

        // get the free spot
        int i = freeIndex;

        // update free index with the next free spot
        freeIndex = next[i];

        if (isEmpty(m))
        {
            // if its the first element of the queue store the index to the front
            front[m] = i;
        }
        else
        {
            // else add it to the next array as the next element for the prev one
            next[rear[m]] = i;
        }

        next[i] = -1; // mark new node as end of the queue
        rear[m] = i;  // update rear

        // insert data to arr
        arr[i] = data;
    }

    int dequeue(int m)
    {
        if (isEmpty(m))
            return -1;

        // get the front element index
        int i = front[m];

        // update front to the next element
        front[m] = next[i];

        // add this i to the free list
        next[i] = freeIndex;

        // update free spot to i
        freeIndex = i;

        return arr[i];
    }
};

int main()
{
    KQueue q(4, 2);
    q.enqueue(1, 0);
    q.enqueue(3, 1);
    q.enqueue(2, 0);
    q.enqueue(4, 1);
    q.enqueue(4, 1);

    cout << q.dequeue(0) << endl;
    cout << q.dequeue(0) << endl;
    cout << q.dequeue(0) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
}