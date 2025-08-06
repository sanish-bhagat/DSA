#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &s, int x)
{
    solve(s, x);
    return s;
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int x = 1;

    stack<int> res = pushAtBottom(s, x);

    while (!res.empty())
    {
        cout << res.top() << endl;
        res.pop();
    }
}