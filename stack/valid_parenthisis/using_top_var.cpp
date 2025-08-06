#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool check(char s1, char s2) {
    if((s1 == '(' && s2 == ')') || (s1 == '{' && s2 == '}') || (s1 == '[' && s2 == ']'))
        return true;
    
    else
        return false;
}

bool isBalanced(string &s)
{
    //top is used as a virtual stack
    int top = -1;

    for(int i =0; i<s.length(); i++) {

        //push char if stack is empty or no match
        if(top < 0 || !check(s[top], s[i])) {
            top++;
            s[top] = s[i];
        }
        else {
            //pop from stack if match is found
            top--;
        }
    }

    //return true agar stack is empty
    return top == -1;
}

int main()
{
    string s = "{[()]}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}