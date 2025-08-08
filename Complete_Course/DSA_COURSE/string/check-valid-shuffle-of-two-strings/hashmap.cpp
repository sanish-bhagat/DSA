#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool validShuffle(string &s1, string &s2, string &shuffle)
{

    int n1 = s1.size(), n2 = s2.size(), n = shuffle.size();

    if (n1 + n2 != n)
        return false;

    unordered_map<int, int> freq;

    for (int i = 0; i < n1; i++)
        freq[s1[i]]++;

    for (int i = 0; i < n2; i++)
        freq[s2[i]]++;

    for (int i = 0; i < n; i++)
    {

        if (freq.find(shuffle[i]) != freq.end())
            freq[shuffle[i]]--;

        else
            return false;
    }

    for (auto i : freq)
    {
        if (i.second != 0)
            return false;
    }

    return true;
}

int main()
{
    string str1 = "BA", str2 = "XY", shuffle = "ABYX";

    (validShuffle(str1, str2, shuffle) == true)
        ? printf("YES")
        : printf("NO");
    cout << endl;

    return 0;
}