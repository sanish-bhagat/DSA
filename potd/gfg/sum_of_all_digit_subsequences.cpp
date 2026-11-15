#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//! TC is O(n)
//! SC is O(1)

int subsequenceSum(string &s)
{
    long long digitSum = 0;
    int n = s.size();

    // calculate the sum of all digits
    for (char ch : s)
        digitSum = (digitSum + ch - '0') % MOD;

    long long digitFreq = 1;

    // each digit appears in 2^(n-1) subsequences
    for (int i = 1; i < n; i++)
        digitFreq = (digitFreq * 2) % MOD;

    return (digitSum * digitFreq) % MOD;
}

int main()
{
    string s = "123";
    cout << subsequenceSum(s);
}