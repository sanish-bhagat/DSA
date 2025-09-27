#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

//! TC is O(n)
//! SC is O(n)

queue<int> reverseQueue(queue<int> q) {
    stack<int> st;

    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    print(q) ;
    cout << endl;

    queue<int> res = reverseQueue(q);
    print(res);
}