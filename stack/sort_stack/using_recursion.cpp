#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

void sortedInsert(stack<int> &st, int num) {

    //if stack is empty or the element is small than the top element, then push the num
    if(st.empty() || st.top() <= num) {
        st.push(num);
        return;
    }

    //else, find its correct position and place it in it
    int top = st.top();
    st.pop();
    sortedInsert(st, num);
    st.push(top);
}

void sortStack(stack<int> &st) {
    if(!st.empty()) {
        //pop the element
        int top = st.top();
        st.pop();

        //recursive call
        sortStack(st);

        //place the curr top element in its correct position
        sortedInsert(st, top);
    }
}

int main(void) {
    stack<int> st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    sortStack(st);
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    return 0;
}