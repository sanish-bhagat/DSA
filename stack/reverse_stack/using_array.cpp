#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void reverse(stack<int> &st)
{
    vector<int> arr;

    while (!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }

    for (int i = 0; i < arr.size(); i++)
    {
        st.push(arr[i]);
    }
}

int main()
{
    stack<int> s;

    // Pushing elements to the stack: 4 3 2 1 (bottom to top)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Reversing the stack
    reverse(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}