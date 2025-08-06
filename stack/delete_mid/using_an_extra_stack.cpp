#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void deleteMid(stack<char> &st, int n) {
    stack<char> temp;
    int count = 0;

    //push the first elements till mid - 1
    while(count < n / 2) {
        temp.push(st.top());
        st.pop();
        count++;
    }

    //pop the middle element
    st.pop();

    //push the first elements popped earlier
    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack<char> st;
 
    //push elements into the stack
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    st.push('7');
 
    deleteMid(st, st.size());
 
    // Printing stack after deletion
    // of middle.
    while (!st.empty())
    {
        char p=st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}