#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

void sortStack(stack<int> &st)
{
    stack<int> tempStack;

    while (!st.empty())
    {
        //top element of input stack nikalo
        int temp = st.top();
        st.pop();

        //tempStack mein jb tak temp element se smaller element h tab tak usko input stack mein push krrdo
        while (!tempStack.empty() && tempStack.top() < temp)
        {
            st.push(tempStack.top());
            tempStack.pop();
        }

        //curr element ko uske cprrect position mein insert krrdo in temp stack
        tempStack.push(temp);
    }

    //elements copy krrlo
    while (!tempStack.empty())
    {
        st.push(tempStack.top());
        tempStack.pop();
    }
}

int main(void)
{
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}