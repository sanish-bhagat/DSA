#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool checkRedundancy(string &s)
{
    // store opening brackets, operands and operators in st
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        // if an closing bracket is encountered -> check for operators in a set of paranthesis
        if (s[i] == ')')
        {
            char top = st.top();
            st.pop();

            // immediate pop has '(' -> redundant set of brackets
            bool flag = true;

            // check for operators in this set of paranthesis
            while (!st.empty() && top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;

                top = st.top();
                st.pop();
            }

            // if no operators founded in this set -> redundant brackets
            if (flag)
                return true;
        }

        // push '(', operands, operators
        else
            st.push(s[i]);
    }

    // no redundant brackets
    return false;
}

int main()
{
    string s = "(a+b+(c+d))";

    cout << checkRedundancy(s);
}