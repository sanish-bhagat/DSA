#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int evaluatePostfix(vector<string> &arr)
{
    stack<int> st;

    for (string num : arr)
    {   
        //any number is encountered - be it +ve or -ve
        //''(single quotes) is used as we are comparing a char
        if (isdigit(num[0]) || num.size() > 1 && num[0] == '-')
            st.push(stoi(num)); //convert it into an integer while pushing into the stack
        else
        {
            //pop-out two element froom the stack to perform operations on that numbers
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            //find the result for the specific operators
            //""(double quotes) is used to compare as the operator or element of the array is a string
            if (num == "+")
                st.push(val2 + val1);
            else if (num == "-")
                st.push(val2 - val1);
            else if (num == "*")
                st.push(val2 * val1);
            else
                st.push(val2 / val1);
        }
    }

    //return the result which is stored in the stack
    return st.top();
}

int main()
{
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << evaluatePostfix(arr) << endl;
    return 0;
}