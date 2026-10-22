#include <bits/stdc++.h>
using namespace std;

// checks whether the given string can be converted into a palindrome
bool isPossible(string &s)
{
    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1])
            return false;
    }

    return true;
}

//! TC is O(n)
//! SC is O(n)

int minSum(string &s)
{
    // string cannot be converted into palindrome
    if (!isPossible(s))
        return -1;

    int n = s.size();

    // copy known characters to their symmetric '?' positions
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] != '?')
            s[i] = s[n - i - 1];

        else if (s[i] != '?' && s[n - i - 1] == '?')
            s[n - i - 1] = s[i];
    }

    vector<char> st;

    // fill consecutive '?' using the nearest known character on the left
    for (int i = 0; i < n;)
    {
        if (s[i] != '?')
        {
            st.push_back(s[i]);
            i++;
        }

        else
        {
            if (!st.empty())
            {
                while (i < n && s[i] == '?')
                    s[i++] = st.back();

                st.pop_back();
            }
            else
                i++;
        }
    }

    // fill remaining '?' using the nearest known character on the right
    for (int i = n - 1; i >= 0;)
    {
        if (s[i] != '?')
        {
            st.push_back(s[i]);
            i--;
        }

        else
        {
            if (!st.empty())
            {
                while (i >= 0 && s[i] == '?')
                    s[i--] = st.back();

                st.pop_back();
            }

            else
                i--;
        }
    }

    // if any '?' still remain, replace them with 'a'
    for (char &c : s)
        if (c == '?')
            c = 'a';

    // compute the sum of absolute differences of adjacent characters
    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        res += abs((s[i] - 'a') - (s[i + 1] - 'a'));

    return res;
}

int main()
{
    string s = "a???c??c????";
    cout << minSum(s);
}