#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + k)
//! SC is O(n)

string lexicographicallySmallest(string &s, int k)
{
    int l = s.size();

    // string is of even length -> double the value of k
    if (l & (l - 1))
        k += k;

    // string length is odd -> half the value of k
    else
        k /= 2;

    // base case
    if (k >= l)
        return "-1";

    string ans = "";

    // monotonic increasing stack
    stack<char> st;

    // traverse through the chars and process them
    for (int i = 0; i < l; i++)
    {
        // remove the smaller char to maintain the increasing order of stack
        while (!st.empty() && k > 0 && st.top() > s[i])
        {
            st.pop();
            k--;
        }

        // push curr char into the stack
        st.push(s[i]);
    }

    // remove remaining chars from stack
    while (k > 0)
    {
        st.pop();
        k--;
    }

    // build the ans string
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // reverse the ans string to get the lexicographically smaller string
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "fooland";
    int k = 2;

    cout << lexicographicallySmallest(s, k);
}