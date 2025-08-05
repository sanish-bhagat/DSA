#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

queue<int> rearrangeQueue(queue<int> q)
{
    // if the size of the queue is odd then neglect the last element of the queue
    if (q.size() % 2 != 0)
    {
        queue<int> temp;
        int n = q.size() - 1;

        // drop the last element of the queue
        for (int i = 0; i < n; i++)
        {
            temp.push(q.front());
            q.pop();
        }

        q = temp;
    }

    stack<int> st;
    int halfSize = q.size() / 2;

    // push the first half of the queue into the stack
    for (int i = 0; i < halfSize; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // push the elements of the stack into the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // push the curr first half of the queue to th back of the queue
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // now push the curr first half of the queue into the stack
    for (int i = 0; i < halfSize; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // now first push the top of the satck then fron of the queue into the queue to get the output
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q = rearrangeQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}