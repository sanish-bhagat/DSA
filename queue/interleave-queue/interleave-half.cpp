#include <iostream>
#include <queue>
using namespace std;

//TC is O(N)
//SC is O(N)

void interleaveHalf(queue<int> &q)
{
    int halfSize = q.size() / 2;

    queue<int> firstHalf;

    for (int i = 0; i < halfSize; i++)
    {
        int val = q.front();
        q.pop();
        firstHalf.push(val);
    }

    while (!firstHalf.empty())
    {
        int val = firstHalf.front();
        firstHalf.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    interleaveHalf(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}