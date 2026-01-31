#include <bits/stdc++.h>
using namespace std;

//! TC is O(1)
//! SC is O(n + k)

class kQueues
{
    int n, k, freeIndex;
    vector<int> arr, front, rear, next;

public:
    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;

        arr.resize(n);
        front.resize(k, -1);
        rear.resize(k, -1);
        next.resize(n);

        // intialise all spaces as free
        freeIndex = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        // -1 indciates the end of the list
        next[n - 1] = -1;
    }

    // checks if the qn is full
    bool isFull(int qn)
    {
        return (freeIndex == -1);
    }

    // checks if the qn is empty
    bool isEmpty(int qn)
    {
        return (front[qn] == -1);
    }

    bool enqueue(int x, int qn)
    {
        // arr is full
        if (isFull(qn))
            return false;

        // next free-index
        int i = freeIndex;
        freeIndex = next[i];

        // queue is empty -> update the front
        if (front[qn] == -1)
            front[qn] = i;

        // link new element to the prev rear
        else
            next[rear[qn]] = i;

        // update the rear
        rear[qn] = i;

        // store the element in the arr
        arr[i] = x;

        // mark the end of the lsit
        next[i] = -1;

        return true;
    }

    int dequeue(int qn)
    {
        // qn is empty
        if (isEmpty(qn))
            return -1;

        // front index of qn
        int i = front[qn];

        // update the front with the next element
        front[qn] = next[i];

        // queue becomes empty
        if (front[qn] == -1)
            rear[qn] = -1;

        // add the dequeued position as a freeindex
        next[i] = freeIndex;
        freeIndex = i;

        // return the dequeued element
        return arr[i];
    }
};

int main()
{
    int n = 10, k = 3;
    kQueues queues(n, k);

    cout << queues.enqueue(10, 0) << " ";
    cout << queues.enqueue(20, 1) << " ";
    cout << queues.enqueue(30, 0) << " ";
    cout << queues.enqueue(40, 2) << " ";

    cout << queues.dequeue(0) << " ";
    cout << queues.dequeue(1) << " ";
    cout << queues.dequeue(2) << " ";
    cout << queues.dequeue(0) << " ";
    cout << queues.dequeue(0) << " ";

    return 0;
}