#include <bits/stdc++.h>
using namespace std;

//! Tc is O(n + k)
//! SC is O(n)

int minStringValue(string &s, int k)
{
    vector<int> freq(26, 0);

    // compute the freq of the char
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    // remove k char having higher freq
    while (k > 0)
    {
        // find the max element in the array and then subtract from freq.begin() to get the index
        int maxIndex = max_element(freq.begin(), freq.end()) - freq.begin();

        if (freq[maxIndex] > 0)
            freq[maxIndex]--;

        k--;
    }

    // calculate the sum of the squares of the freq
    int res = 0;
    for (int i : freq)
    {
        res += i * i;
    }

    return res;
}

int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;

    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);

    return 0;
}