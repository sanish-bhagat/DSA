#include <iostream>
#include <queue>
using namespace std;

class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        { // frist element to push
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        if (front == -1)
        { // to check queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        { // first element
            front = rear = -1;
        }
        else if (front == size - 1)
        { // to maintain cyclic nature
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }

            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(4);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);

    cq.dequeue();

    cq.display();
}