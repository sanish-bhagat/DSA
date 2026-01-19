#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SCC is O(n)

string removeKdig(string s, int k)
{
    int n = s.size();

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        // remove larger digits when possible -> always keep smaller digits at the left o make the sequence smaller
        while (!st.empty() && k > 0 && st.top() > c)
            st.pop(), k--;

        // push the curr digit in the stack if it meets the condn
        if (!st.empty() || c != '0')
            st.push(c);
    }

    // remove remaining digit if any
    while (!st.empty() && k--)
        st.pop();

    if (st.empty())
        return "0";

    // build the result string from the stack
    while (!st.empty())
    {
        s[n - 1] = st.top();
        st.pop();

        n -= 1;
    }

    return s.substr(n);
}

int main()
{
    string s = "765028321";
    int k = 5;
    cout << removeKdig(s, k);
    return 0;
}