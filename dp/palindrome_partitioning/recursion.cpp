#include <bits/stdc++.h>
using namespace std;

// function to return if a substring is a palindrome
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++, j--;
    }

    return true;
}

//! TC is O(n * 2^n)
//! SC is O(n)

int palPartitionRec(string s, int i, int j)
{
    // traversed the substring or the substring is already a palindrome -> no cuts needed
    if (i >= j || isPalindrome(s, i, j))
        return 0;

    int res = INT_MAX, cuts;

    // try through all the possible partitions and find the minimum cuts needed
    for (int k = i; k < j; k++)
    {
        // perform a cut and recursively for the rest of the parts
        cuts = 1 + palPartitionRec(s, i, k) + palPartitionRec(s, k + 1, j);

        // pick the minimum cut
        res = min(res, cuts);
    }

    return res;
}

int palPartition(string &s)
{
    return palPartitionRec(s, 0, s.size() - 1);
}

int main()
{
    string s = "geek";

    cout << palPartition(s) << endl;
    return 0;
}