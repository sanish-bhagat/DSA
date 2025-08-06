#include <bits/stdc++.h>
using namespace std;

//! SC is O(n)

class Stack
{
    vector<int> arr;
    int k, n;
    //keep track of the top element index of every stack
    vector<int> top;
    //keep track of the next element for every element
    vector<int> next;
    //ptr to keep track of the freespot in the array
    int freeIndex;

public:
    Stack(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr.resize(n);
        top.resize(k, -1);
        next.resize(n);

        //set the next[i] to its next element
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        //set last element to -1
        next[n - 1] = -1;

        freeIndex = 0;
    }

    //! TC is O(1)
    void push(int data, int m)
    {
        if (freeIndex == -1)
            return;

        //get the free spot
        int i = freeIndex;

        //update free to next free spot
        freeIndex = next[i];

        //update next of top and top for stack m
        next[i] = top[m];
        top[m] = i;

        //allot the value in the array
        arr[i] = data;
    }

    //! TC is O(1)
    int pop(int m)
    {
        //check if stack is empty
        if (top[m] == -1)
            return -1;

        //get the index of the top element of the stack
        int i = top[m];

        //update the top to the next element of the stack
        top[m] = next[i];

        //update the next[i] to the curr head of the free list
        next[i] = freeIndex;

        //update the free ptr to i as i is the curr free spot
        freeIndex = i;

        return arr[i];
    }
};

int main()
{
    Stack s(5, 2);
    s.push(1, 0);
    s.push(3, 1);
    s.push(2, 0);
    s.push(4, 1);

    cout << s.pop(0) << endl;
    cout << s.pop(1) << endl;
}