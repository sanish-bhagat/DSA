#include <bits/stdc++.h>
using namespace std;

queue<int> rearrangeQueue(queue<int> q)
{
    int n = q.size();

    if (n % 2 != 0)
    {
        queue<int> temp;
        n = q.size() - 1;

        for (int i = 0; i < n; i++)
        {
            temp.push(q.front());
            q.pop();
        }

        q = temp;
    }

    vector<int> ans(n);

    int i = 0, j = 0;

    for (; i < n / 2; i++)
    {
        ans[2 * i] = q.front();
        q.pop();
    }

    for (; j < n / 2; j++)
    {
        ans[2 * j + 1] = q.front();
        q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        q.push(ans[i]);
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