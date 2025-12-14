#include <bits/stdc++.h>
using namespace std;

int solve(string s, int low, int high, vector<vector<int>> &memo)
{
    // base case: traversed the whole string
    if (low > high)
        return 0;

    // base case: same position, therefore same character
    if (low == high)
        return 1;

    // already computed subproblem
    if (memo[low][high] != -1)
        return memo[low][high];

    // character matches ->
    // try subsequences excluding left character + try subsequences excluding the right characters +
    // since character matches, therefore every palindromic subsequence inside can be extended to form new palindromes
    if (s[low] == s[high])
        return memo[low][high] = solve(s, low + 1, high, memo) + solve(s, low, high - 1, memo) + 1;

    // try sequences excluding left or right characters - remove doubly counted middle palindromes
    // once it is count during left recursion and once it is count during right recursion, so we remove the count once
    return memo[low][high] = solve(s, low + 1, high, memo) + solve(s, low, high - 1, memo) - solve(s, low + 1, high - 1, memo);
}

//! TC is O(n * n)
//! SC is O(n * n)

int countPS(string &s)
{
    int n = s.size();

    vector<vector<int>> memo(n, vector<int>(n, -1));

    // recursively explore all the palindromic subsequences and return their count
    return solve(s, 0, n - 1, memo);
}

int main()
{
    string s = "aab";
    cout << countPS(s);
}