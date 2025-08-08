#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void deleteRec(stack<char> &st, int n, int current) {

    //base case - delete the middle element
    if(current == n / 2) {
        st.pop();
        return;
    }

    char x = st.top();
    st.pop();
    current += 1;

    deleteRec(st, n, current);

    st.push(x);
}

void deleteMid(stack<char> &st, int n) {
    deleteRec(st, n, 0);
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