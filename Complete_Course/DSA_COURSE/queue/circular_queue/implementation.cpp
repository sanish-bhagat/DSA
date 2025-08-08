#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size, front, capacity;

public:
    Queue(int n)
    {
        capacity = n;
        arr = new int[n];
        size = 0;
        front = 0;
    }

    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        // set the rear
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
            return -1;

        int res = arr[front];

        // update the front and size
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    int getFront()
    {
        if (size == 0)
            return -1;

        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;

        // get the rear index
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
};

int main()
{
    Queue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    // q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << q.dequeue() << endl;
}