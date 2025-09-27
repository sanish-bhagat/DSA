#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int *top;
    int n, k;
    int stackSize;

public:
    Stack(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        top = new int[k];
        stackSize = n / k;

        for (int i = 0; i < k; i++)
        {
            top[i] = i * stackSize - 1;
        }
    }

    bool isFull(int m)
    {
        return top[m] == (m + 1) * stackSize - 1;
    }

    bool isEmpty(int m)
    {
        return top[m] == m * stackSize - 1;
    }

    void push(int x, int m)
    {
        if (isFull(m))
        {
            cout << "Stack is Full" << endl;
            return;
        }

        top[m]++;
        arr[top[m]] = x;
    }

    int pop(int m)
    {
        if (isEmpty(m))
            return -1;

        int value = arr[top[m]];
        top[m]--;
        return value;
    }
};

int main()
{
    Stack ks(10, 2); // 2 stacks in an array of size 10 (each gets 5 slots)

    ks.push(10, 0);
    ks.push(20, 0);
    ks.push(30, 1);
    ks.push(40, 1);
    ks.push(50, 1);
    ks.push(60, 1);
    ks.push(70, 1);
    ks.push(80, 1); // Overflow expected

    cout << ks.pop(0) << endl; // Should print 20
    cout << ks.pop(1) << endl; // Should print 50

    return 0;
}
