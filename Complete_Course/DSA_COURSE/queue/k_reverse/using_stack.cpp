#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + k)
//! SC is O(k)

queue<int> reverseFirstK(queue<int> q, int k)
{
    // base case
    if (q.empty() || k > q.size())
        return q;

    if (k <= 0)
        return q;

    stack<int> st;

    //pop the first k elements of the queue and push them into the stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    //push the elements of the stack in the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    //pop the reminaing elements from the front and push them into the back of the queue
    for (int i = 0; i < q.size() - k; i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);
    }

    return q;
}

int main()
{
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    int k = 3;
    queue = reverseFirstK(queue, k);

    // Printing queue
    while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    return 0;
}