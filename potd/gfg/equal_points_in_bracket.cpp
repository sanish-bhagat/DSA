#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int findIndex(string &s)
{
    int n = s.size();

    // keep track of open and closing bracket
    int openCnt = 0, closeCnt = 0;

    // count the total no. of closing brackets
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            closeCnt++;
    }

    for (int i = 0; i <= n; i++)
    {
        // equal point found
        if (openCnt == closeCnt)
            return i;

        if (i < n)
        {
            // count opening brackets before next index
            if (s[i] == '(')
                openCnt++;

            // count closing bracket from next index onwards
            if (s[i] == ')')
                closeCnt--;
        }
    }

    return -1;
}

int main()
{
    string s = "(())))(";
    cout << findIndex(s);
}