#include <bits/stdc++.h>
using namespace std;

// function to tell whether the given substring is  a palindrome or not
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++, j--;
    }

    return true;
}

int palPartitionRec(int i, int j, string &s, vector<vector<int>> &memo)
{
    // substring is empty or is a palindrome -> no cuts needed
    if (i >= j || isPalindrome(i, j, s))
        return memo[i][j] = 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;

    // try through all the partitions and find the min cuts needed
    for (int k = i; k < j; k++)
    {
        // perform a cut at the given partition and recurse for the rest of the parts
        int cuts = 1 + palPartitionRec(i, k, s, memo) + palPartitionRec(k + 1, j, s, memo);

        // keep track of the min cuts
        res = min(res, cuts);
    }

    return memo[i][j] = res;
}

//! TC is O(n ^ 3)
//! SC is O(n * n)

int palPartition(string &s)
{
    int n = s.size();

    // 2d memo[] -> stores the min cuts required for different size of substrings
    vector<vector<int>> memo(n, vector<int>(n, -1));

    // recursively explore the given substring and compute the min cuts required
    return palPartitionRec(0, n - 1, s, memo);
}

int main()
{
    string s = "geek";

    cout << palPartition(s) << endl;
    return 0;
}