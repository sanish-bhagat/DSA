#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void rec(stack<int> &st,int x) {
    //push the element if the stack is empty
    if(st.empty()) {
        st.push(x);
    }
    else {
        //store the curr top element in a temp variable
        int temp = st.top();
        st.pop();

        //recursive call - for the left out elements in the stack
        rec(st, x);

        //push the popped out element again into the stack
        st.push(temp);
    }
}

stack<int>  insertToBottom(stack<int> &st, int x) {
    rec(st, x);

    return st;
}

int main()
{
    // Input
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
 
    int N = 7;
 
    S = insertToBottom(S, N);
    
    while(!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }

    return 0;
}