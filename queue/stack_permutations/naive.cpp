#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool checkPerm(vector<int> &a, vector<int> &b) {
    queue<int> q1, q2;
    stack<int> st;

    for(int i : a)
        q1.push(i);

    for(int j : b)
        q2.push(j);

    while(!q1.empty()) {
        int element = q1.front();
        q1.pop();
        st.push(element);

        while(!st.empty() && st.top() == q2.front()) {
            st.pop();
            q2.pop();
        }
    }

    return (q1.empty() && st.empty());
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};

    if(checkPerm(a, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;  

    return 0;
}