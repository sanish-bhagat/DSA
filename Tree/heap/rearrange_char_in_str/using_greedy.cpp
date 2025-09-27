#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string rearrangeString(string s)
{
    int n = s.length();

    // generate the freq of all char, store the maxFreq and its corresponding char
    unordered_map<char, int> freq;
    int maxCnt = 0;
    char ch;

    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;

        if (freq[s[i]] > maxCnt)
        {
            maxCnt = freq[s[i]];
            ch = s[i];
        }
    }

    // if maxCnt is greater then it is not  possible to generate a string
    if(maxCnt > ((n+1)/2))
        return "";

    string res(n, ' ');

    // fill the even positions with the maxFreq char first
    int ind = 0;
    while (maxCnt > 0)
    {
        res[ind] = ch;
        ind += 2;
        maxCnt--;
    }

    // make the freq to 0
    freq[ch] = 0;

    // fill the odd positions with the remainig char
    for (char c = 'a'; c <= 'z'; c++)
    {
        while (freq[c])
        {

            // if still any even positions left then fill it with the remaining char first,
            //  else fill the odd positions
            ind = (ind >= n) ? 1 : ind;
            res[ind] = c;
            ind += 2;
            freq[c]--;
        }
    }

    return res;
}

int main()
{
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}