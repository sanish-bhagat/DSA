#include <bits/stdc++.h>
using namespace std;

string countBits(long long N)
{
    string s;

    while (N > 0)
    {
        // curr bit is a set bit -> push 1
        if (N & 1)
            s += '1';

        // else push 0
        else
            s += '0';

        N = N >> 1;
    }

    return s;
}

//! TC is O(log n)
//! SC is O(log n)

int isPalindrome(long long N)
{
    // convert the integer N to binary
    string s = countBits(N);

    int i = 0, j = s.size() - 1;

    // check for palindrome
    while (i < j)
    {
        if (s[i++] != s[j--])
            return 0;
    }

    return 1;
}

int main()
{
    long long N = 17;
    cout << isPalindrome(N);
}