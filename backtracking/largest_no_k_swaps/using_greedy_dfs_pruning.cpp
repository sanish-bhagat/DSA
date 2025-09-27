#include <bits/stdc++.h>
using namespace std;

void findMax(string &s, int k, int idx, string &maxNum)
{
    // base case: no swap lefts or index out of range
    if (k == 0 || idx >= s.size())
        return;

    // find the max_digit starting from idx
    char maxDigit = *max_element(s.begin() + idx, s.end());

    // if curr digit is already max, no need to swap
    if (s[idx] == maxDigit)
    {
        findMax(s, k, idx + 1, maxNum);
        return;
    }

    // find the max_digit from the right side and swap it
    for (int j = s.size() - 1; j > idx; j--)
    {
        if (s[j] == maxDigit)
        {
            swap(s[j], s[idx]);

            // update with the largest no.
            maxNum = max(maxNum, s);

            // recursive call for one less swap and next index
            findMax(s, k - 1, idx + 1, maxNum);

            // backtrack: to explore more combinations
            swap(s[j], s[idx]);
        }
    }
}

//! TC is O(n * k)
//! SC is O(n)

string findMaximumNum(string s, int k)
{
    string maxNum = s;

    // recursive function to find the largest no.
    findMax(s, k, 0, maxNum);

    return maxNum;
}

int main()
{

    string s = "7599";
    int k = 2;

    cout << findMaximumNum(s, k) << endl;

    return 0;
}