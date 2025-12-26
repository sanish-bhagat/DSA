#include <bits/stdc++.h>
using namespace std;

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

int palPartitionRec(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
        return 0;

    int res = INT_MAX, cuts;

    for (int k = i; k < j; k++)
    {
        cuts = 1 + palPartitionRec(s, i, k) + palPartitionRec(s, k + 1, j);

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