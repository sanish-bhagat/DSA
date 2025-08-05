#include <iostream>
#include <stack>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void insertAtBottom(stack<int> &st, int x)
{
    if (st.size() == 0)
    {
        st.push(x);
    }
    else
    {
        int a = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(a);
    }
}

void reverse(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();

        //recursive call for the rest of the element
        reverse(st);
        
        //insert the curr top element at the bottom
        insertAtBottom(st, x);
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