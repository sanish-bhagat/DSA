#include <bits/stdc++.h>
using namespace std;

void rearrangeQueue(queue<int> &q)
{
    stack<int> st;

    int halfSize = q.size() / 2;

    // push the first half in the stack
    for (int i = 0; i < halfSize; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // enqueue the stack elements
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // dequeue and enqueue the second half elements
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // again push the first half in the stack -> to reverse them
    for (int i = 0; i < halfSize; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // interleave elements from first and second half
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{

    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);
    rearrangeQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}