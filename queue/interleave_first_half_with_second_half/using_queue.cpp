#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

queue<int> rearrangeQueue(queue<int> q)
{

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

    queue<int> firstHalf;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
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