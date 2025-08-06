#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * 2 ^ n)
//! SC is O(1) , if printing and O(n * 2 ^ n) if storing

void printSubs(string s)
{

    int n = s.length();
    int total = (1 << n); // 1 << n = 2 ^ n

    for (int i = 0; i < total; i++)
    {

        string str = "";
        for (int j = 0; j < n; j++)
        {

            if (i & (1 << j))
            {
                str += s[j];
            }
        }

        cout << str << endl;
    }
}

int main()
{
    string s = "ab";
    printSubs(s);
    return 0;
}
