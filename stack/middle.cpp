#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &input, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        input.pop();
        return;
    }

    int num = input.top();
    input.pop();

    // recusive call
    solve(input, count + 1, size);

    input.push(num);
}

void deleteMiddle(stack<int> &input, int N)
{
    int count = 0;
    solve(input, count, N);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMiddle(s, 5);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
