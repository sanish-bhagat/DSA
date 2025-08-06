#include <bits/stdc++.h>
using namespace std;

//! only valid if there are no nested paranthesis
//! TC is O(n)
//! SC is O(1)

bool findRedundant(string &s)
{
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            int j = i + 1;
            bool hasOperator = false;

            while (j < n && s[i] != ')')
            {
                if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                    hasOperator = true;

                j++;
            }

            if (j >= n)
                break;

            if (!hasOperator)
                return true;

            i = j;
        }
    }

    return false;
}

int main()
{
    string s = "(a+b)";
    cout << findRedundant(s);
    return 0;
}