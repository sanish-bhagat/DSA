#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:

    //! TC is O(1)
    void push(int x)
    {
        q1.push(x);
    }

    //! TC is O(n)
    void pop()
    {
        if (q1.empty())
            return;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        swap(q1, q2);
    }

    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // store the front element
        int temp = q1.front();

        // pop the element from q1
        q1.pop();

        q2.push(temp);

        swap(q1, q2);

        return temp;
    }

    int size()
    {
        return q1.size();
    }

    bool isempty()
    {
        return q1.size() == 0;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Size: " << st.size() << endl;

    while (!st.isempty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\nSize: " << st.size();
}