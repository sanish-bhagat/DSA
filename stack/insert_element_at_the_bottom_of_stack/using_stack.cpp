#include<bits/stdc++.h>
using namespace std;

//! Recusrive approach is efficient as recursive calls work faster

//! TC is O(n)
//! SC is O(n)

void insertToBottom(stack<int> &st, int x) {
    stack<int> temp;

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    temp.push(x);

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
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
 
    insertToBottom(S, N);
    
    while(!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }

    return 0;
}