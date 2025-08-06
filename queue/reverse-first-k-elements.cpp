#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// TC is O(N)
// SC is O(K)

queue<int> revByK(queue<int> &q, int k)
{
    stack<int> s;

    // step1 - pop first k from q and put into stack
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step2 - fetch from stack and push into q
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step3 - fetch first (n-k) element from q and push back
    int t = q.size() - k;

    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
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

    queue<int> ans = revByK(q, 2);

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
}