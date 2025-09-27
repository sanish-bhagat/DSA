#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxLength(string &s)
{
    //create a stack to store the indexes 
    stack<int> st;
    //push -1 to help calculate the valid substr len starting from index 1
    st.push(-1);

    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        //if the chcar is an opening bracket then push it into the stack
        if (s[i] == '(')
            st.push(i);

        else
        {
            //else its a closing bracket pop it
            st.pop();

            //after popping if the st is empty push the curr index as a new base for the next valid substr
            if (st.empty())
                st.push(i);

            //else calculate the len of valid substr
            else
                maxLen = max(maxLen, i - st.top());
        }
    }

    return maxLen;
}

int main()
{
    string s = ")()())";
    cout << maxLength(s) << endl;

    return 0;
}