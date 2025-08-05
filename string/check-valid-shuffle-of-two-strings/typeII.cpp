#include <bits/stdc++.h>
using namespace std;

//! TC is O(m * n * log n)
//! SC is O(n)

bool isShuffledSubstring(string &s1, string &s2)
{

    int n = s1.length(), m = s2.length();

    if (n > m)
        return false;

    //sort krrdo s1 string ko
    sort(s1.begin(), s1.end());

    for (int i = 0; i < m; i++)
    {

        //as after this, length of the remaining string s2 will be less than s1
        if (i + n - 1 >= m)
            return false;

        string str = "";

        //new string mein str2 k characters push krrte rho
        for (int j = 0; j < n; j++)
            str.push_back(s2[i + j]);

        //sort krrdo new string ko
        sort(str.begin(), str.end());

        if (s1 == str)
            return true;
    }
}

int main()
{
    // Input str1 and str2
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";

    // Function return true if
    // str1 is shuffled substring
    // of str2
    bool a = isShuffledSubstring(str1, str2);

    // If str1 is substring of str2
    // print "YES" else print "NO"
    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}