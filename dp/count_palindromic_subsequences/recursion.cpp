#include <bits/stdc++.h>
using namespace std;

int solve(string s, int low, int high)
{
    // base case: traversed the whole string
    if (low > high)
        return 0;

    // base case: same position, therefore same character
    if (low == high)
        return 1;

    // character matches ->
    // try subsequences excluding left character + try subsequences excluding the right characters +
    // since character matches, therefore every palindromic subsequence inside can be extended to form new palindromes
    if (s[low] == s[high])
        return solve(s, low + 1, high) + solve(s, low, high - 1) + 1;

    // try sequences excluding left or right characters - remove doubly counted middle palindromes
    // once it is count during left recursion and once it is count during right recursion, so we remove the count once
    return solve(s, low + 1, high) + solve(s, low, high - 1) - solve(s, low + 1, high - 1);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int countPS(string &s)
{
    // recursively explore all the palindromic subsequences and return their count
    return solve(s, 0, s.size() - 1);
}

int main()
{
    string s = "aab";
    cout << countPS(s);
}