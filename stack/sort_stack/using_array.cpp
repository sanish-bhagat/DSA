#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

void sortStack(stack<int> &st) {
    vector<int> arr;

    while(!st.empty()) {
        arr.push_back(st.top());
        st.pop();
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++) {
        st.push(arr[i]);
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