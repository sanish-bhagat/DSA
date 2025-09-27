#include <bits/stdc++.h>
using namespace std;

//! TC is O(n*n)
//! SC is O(1)

string removeDuplicates(string &s)
{

    int index = 0;

    for (int i = 0; i < s.size(); i++)
    {

        int j;
        for (j = 0; j < i; j++)
        {

            if (s[i] == s[j])
                break;
        }

        if (i == j)
            s[index++] = s[i];
    }

    s.resize(index);

    return s;
}

int main()
{
    string s = "geeksforgeeks";
    cout << removeDuplicates(s) << endl;
    return 0;
}