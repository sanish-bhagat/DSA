#include <bits/stdc++.h>
using namespace std;

// function to check if the substring is a plaindrome or not
bool checkPal(string &s, int low, int high)
{
    if (low > high)
        return false;

    while (low < high)
    {
        if (s[low] != s[high])
            return false;

        low++;
        high--;
    }

    return true;
}

//! TC is O(n * n * n)
//! SC is O(1)

string getLongestPal(string &s)
{
    int n = s.size();

    int start = 0, maxLen = 1;

    // generate all possible substrings
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // for each substring,
            // if it is a palindrome and its length is > than the longest palindrome found so far ->
            // update the start and the maxLen pointer
            if (checkPal(s, i, j) && (j - i + 1) > maxLen)
            {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    // return the longest palindromic substring
    return s.substr(start, maxLen);
}

int main()
{
    string s = "forgeeksskeegfor";
    cout << getLongestPal(s) << endl;
    return 0;
}