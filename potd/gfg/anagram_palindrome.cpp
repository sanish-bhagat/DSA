#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool canFormPalindrome(string &s)
{
    // frequency hashmap
    vector<int> freq(26, 0);

    // build the hashmap
    for (char c : s)
        freq[c - 'a']++;

    // keep track of no. of distinct char that has odd freq
    // anytime this count > 1 -> the given string cannot be arranged as a valid palindrome
    int mid = 0;

    // traverse through the freq[]
    for (int i = 0; i < 26; i++)
    {
        // char freq is odd -> increment the mid count
        if (freq[i] % 2 != 0)
            mid++;

        // more than one char that has odd freq -> cannot build palindrome
        if (mid > 1)
            return false;
    }

    // given string can be arranged in a valid palindrome
    return true;
}

int main()
{
    string s = "geeksogeeks";
    cout << canFormPalindrome(s);
}