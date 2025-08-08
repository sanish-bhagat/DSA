#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(1)

bool isPalindrome(int n)
{

    string s = to_string(n);
    int len = s.length();

    for (int i = 0; i < len / 2; i++)
    {

        if (s[i] != s[len - i - 1])
            return false;
    }

    return true;
}

bool isPalinArray(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        if (!isPalindrome(arr[i]))
            return false;
    }

    return true;
}

int main()
{
    vector<int> arr = {121, 131, 20};
    bool res = isPalinArray(arr);
    if (res == true)
        cout << "true";
    else
        cout << "false";
}