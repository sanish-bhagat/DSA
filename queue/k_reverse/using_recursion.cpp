#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

// reverse the first k elements and push it into the back of the queue
void kRec(queue<int> &q, int k)
{
    if (k == 0)
        return;

    int x = q.front();
    q.pop();
    kRec(q, k - 1);
    q.push(x);
}

queue<int> reverseFirstK(queue<int> q, int k)
{
    kRec(q, k);
    int s = q.size() - k;

    // pop the remaining elements from the front and push it into the back of the queue
    while (s-- > 0)
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