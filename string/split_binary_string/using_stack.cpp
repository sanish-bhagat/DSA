#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxSubStr(string &s) {
    int n = s.length();
    int cnt = 0, i = 0;
    stack<char> st;
    st.push(s[i]);
    i++;

    while(i < n) {

        while(i < n && st.size() && i < n && (st.top() != s[i])) {
            st.pop();
            i++;
        }

        if(st.empty())
            cnt++;

        while(i < n && (st.empty() || st.top() == s[i])) {
            st.push(s[i]);
            i++;
        }
    }

    if(st.empty())
        return cnt;

    return -1;
}

int main()
{
    string str = "0100110101";
 
    cout << maxSubStr(str);
 
    return 0;
}