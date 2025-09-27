#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool isBalanced(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {

        // insert the opening brackets in the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        // check for the curr closing bracket if the top the stack is the ssame opening bracket or not
        else
        {
            if ((!st.empty()) && ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')))
            {
                st.pop();
            }

            // there is a mismatch - that is there is no opening closing bracket present
            else
                return false;
        }
    }

    return (st.empty());
}

int main()
{
    string s = "{)]}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}