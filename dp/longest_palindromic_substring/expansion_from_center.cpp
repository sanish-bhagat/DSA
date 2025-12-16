#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

string getLongestPal(string &s)
{
    int n = s.size();

    int start = 0, maxLen = 1;

    // traverse the string and treat every character as a potential center of a palindrome
    for (int i = 0; i < n; i++)
    {
        // check for odd(j=0) length palindromes and even(j=1) length palindromes
        for (int j = 0; j <= 1; j++)
        {
            int low = i;
            int high = i + j;

            // keep expanding the current substrings in both the directions and
            // check if the expanding substring remains a palindrome
            while (low >= 0 && high < n && s[low] == s[high])
            {
                int currLen = high - low + 1;

                // founded a greater length palindrome
                if (currLen > maxLen)
                {
                    start = low;
                    maxLen = currLen;
                }

                // expand the character in both directions
                low--;
                high++;
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