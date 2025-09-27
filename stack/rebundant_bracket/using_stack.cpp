#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

//if any operator is present between a pair of closing and opening bracket then it is not said to be redundant

bool checkRedundancy(string &s) {
    stack<int> st;

    for(char ch : s) {

        if(ch == ')') {
            char top = st.top();
            st.pop();

            bool isRedundant = true;

            while(!st.empty() && top != '(') {

                //if any operator is present in the expression
                if(top == '+' || top == '-' || top == '*' || top == '/')
                    isRedundant = false;

                top = st.top();
                st.pop();
            }

            if(isRedundant)
                return true;
        }
        else {
            st.push(ch);
        }
    }

    return 0;
}

void findRedundant(string& s)
{
    bool res = checkRedundancy(s);
    if (res == true)
        cout << "True\n";
    else
        cout << "False\n";
}

int main()
{
    string s = "(a+(b+(c+d)))";
    findRedundant(s);
    return 0;
}