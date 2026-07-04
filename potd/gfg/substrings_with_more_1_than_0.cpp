#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countSubstring(string s)
{
    int n = s.size();

    // required to handle -ve prefix sum cases
    int offset = n;

    // hashset, stores how many times prefix sum 'i' has appeared
    vector<int> freq(2 * n + 1, 0);

    freq[offset] = 1;

    // '1' -> + 1, '0' -> -1
    int prefix = 0;

    // stores how many prev prefix sum are smaller than the curr prefix sum
    long long smaller = 0;

    // stores the total valid substring count
    long long ans = 0;

    for (char c : s)
    {
        if (c == '1')
        {
            // all previous prefix sum is smaller than curr prefix sum ->
            // include their count
            smaller += freq[prefix + offset];

            // increment the running prefix sum
            prefix++;
        }
        else
        {
            // exclude the count of the substrings which has
            // smaller prefix sum than the curr one
            smaller -= freq[prefix - 1 + offset];

            // decrement the running prefix sum
            prefix--;
        }

        // smaller gives the no. of valid substrings ending at the curr position
        ans += smaller;

        // store the curr prefix sum count in hashset
        freq[prefix + offset]++;
    }

    return ans;
}

int main()
{
    string s = "011";
    cout << countSubstring(s);
}