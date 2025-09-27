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
            sum += (s1[i] - '0');

        if (j >= 0)
            sum += (s2[j] - '0');

        // push the digit which is at ones place, update the carry and ptrs
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
        i--;
        j--;
    }

    // remove any leading zeros, now the '0' are at last, since the res is reversed till now
    while (!res.empty() && res.back() == 0)
        res.pop_back();

    // reverse the final string and return it
    reverse(res.begin(), res.end());

    return res;
}

//! TC is O(n)
//! SC is O(n)

string minSum(vector<int> &arr)
{
    // count the freq of the digits
    vector<int> count(10, 0);

    for (int num : arr)
        count[num]++;

    string s1 = "", s2 = "";

    // flag to alternate between s1 and s2
    bool firstNum = true;

    // traverse the count arr[] from 0 to 9
    for (int digit = 0; digit < 10; digit++)
    {
        // add to string until its count > 0
        while (count[digit]--)
        {
            // alternately push between s1 and s2
            if (firstNum)
            {
                // ignore the leading 0 for both nos.
                if (!(s1.empty() && digit == 0))
                    s1.push_back(digit + '0');

                firstNum = false;
            }
            else
            {
                if (!(s2.empty() && digit == 0))
                    s2.push_back(digit + '0');

                firstNum = true;
            }
        }
    }

    // cases when strings might be empty
    if (s1.empty())
        s1 = "0";

    if (s2.empty())
        s2 = "0";

    // add the two min no
    return addString(s1, s2);
}

int main()
{
    vector<int> arr = {6, 8, 4, 5, 2, 3, 0};

    cout << minSum(arr);
    return 0;
}