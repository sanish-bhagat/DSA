#include <bits/stdc++.h>
using namespace std;

//! TC is O(m + (n - m) * 256)
//! SC is O(256)

#define MAX 256

bool compare(int arr1[], int arr2[])
{

    for (int i = 0; i < MAX; i++)
    {

        if (arr1[i] != arr2[i])
            return false;
    }

    return true;
}

bool isShuffledSubstring(string &pat, string &txt)
{

    int m = pat.length(), n = txt.length();

    if (m > n)
        return false;

    //count1[] : to store count of all char of pat    
    //count2[] : to store count of all char of curr window of txt    
    int count1[MAX] = {0}, count2[MAX] = {0};

    for (int i = 0; i < m; i++)
    {
        count1[pat[i]]++;
        count2[txt[i]]++;
    }

    for (int i = m; i < n; i++)
    {

        //compare krro counts of curr window of txt[] and pat[]
        if (compare(count1, count2))
            return true;

        //add the curr char in the curr window
        count2[txt[i]]++;

        //remove the first char of prev window
        count2[txt[i - m]]--;
    }

    if (compare(count1, count2))
        return true;

    return false;
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