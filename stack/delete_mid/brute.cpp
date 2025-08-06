#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void deleteMid(stack<int> &st) {

    vector<int> v;
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    reverse(v.begin(), v.end());
    int n = v.size();

    //if size of the stack is even
    if(n % 2 == 0) {
        int target = n / 2;
        for(int i =0; i<n; i++) {
            if(i == target)
                continue;
            st.push(v[i]);
        }
    }

    //if the size of the stack is odd
    else {
        int target = ceil(n/2);
        for(int i =0; i<n; i++) {
            if(i == target)
                continue;
            st.push(v[i]);
        }
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    deleteMid(st);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}