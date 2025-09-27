#include <bits/stdc++.h>
using namespace std;

class Deque
{

    Deque *head;
    Deque *tail;

public:
    Deque *next;
    Deque *prev;
    int data;

    Deque()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;

        return false;
    }

    int size()
    {
        int len = 0;
        Deque *temp = head;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    void push_front(int data)
    {
        Deque *temp = new Deque[sizeof(Deque)];
        temp->data = data;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    void push_rear(int data)
    {
        Deque *temp = new Deque[sizeof(Deque)];
        temp->data = data;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            tail = temp;
        }
    }

    void pop_front()
    {
        if (!isEmpty())
        {
            Deque *temp = head;
            head = head->next;

            if (head)
                head->prev = NULL;

            // if no elements are present in Deque point head = tail = NULL
            if (head == NULL)
                tail = NULL;

            delete temp;
        }
    }

    void pop_rear()
    {
        if (!isEmpty())
        {
            Deque *temp = tail;
            tail = tail->prev;

            // if tail exists that is it not NULL
            if (tail)
                tail->next = NULL;

            // if no elements are present in Deque point head = tail = NULL
            if (tail == NULL)
                head = NULL;
        }
    }

    void display()
    {
        Deque *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

class Stack : public Deque
{
public:
    void push(int element)
    {
        push_rear(element);
    }

    void pop()
    {
        pop_rear();
    }
};

class Queue : public Deque
{
public:
    void push(int element)
    {
        push_rear(element);
    }
    void pop()
    {
        pop_front();
    }
};

int main()
{
    Deque dq;
    // dq.push_front(1);
    // dq.push_rear(2);
    // dq.push_rear(3);
    // dq.push_rear(4);
    // cout << dq.size() << endl;
    // dq.push_front(5);
    // cout << dq.size() << endl;
    // dq.pop_front();
    // dq.display();

    // Stack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.display();
    // cout << endl;
    // st.pop();
    // st.display();
    // cout << endl;

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    cout << endl;
    q.pop();
    q.display();
    cout << endl;
}