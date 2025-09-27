#include <bits/stdc++.h>
using namespace std;

string addString(string &s1, string &s2)
{
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    int carry = 0;
    string res = "";

    // traverse the string from backward
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;

        // sum up the values by subtracting the ascii value as we are performing opertaions on str
        if (i >= 0)
            sum += s1[i] - '0';

        if (j >= 0)
            sum += s2[j] - '0';

        // push the digit which is at ones place, update the carry and ptrs
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
        i--;
        j--;
    }

    // remove any leading zeros, now the '0' are at last, since the res is reversed till now
    while (!res.empty() && res.back() == '0')
        res.pop_back();

    // reverse the final string and return it
    reverse(res.begin(), res.end());

    return res;
}

//! TC is O(n * logn)
//! SC is O(n)

string minSum(vector<int> &arr)
{
    // sort the given arr[]
    sort(arr.begin(), arr.end());

    // strings to store the two min no
    string s1 = "", s2 = "";

    // traverse the arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // make the first min no. by taking digits placed at the even position
        // push the ascii value as we are storing it as a str
        if (i % 2 == 0)
            s1.push_back(arr[i] + '0');

        // make the second no. by taking the digits placed at the odd positon
        else
            s2.push_back(arr[i] + '0');
    }

    // add the two min no
    return addString(s1, s2);
}

int main()
{
    vector<int> arr = {6, 8, 4, 5, 2, 3, 0};

    cout << minSum(arr);
    return 0;
}