#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool findPattern(string &s)
{
    int sum = 0;

    // traverse for every character, for x -> +1, for y -> -1
    for (char c : s)
    {
        if (c == 'x')
            sum += 1;

        else
            sum -= 1;

        // x should not follow y, y's are coming before x
        if (sum < 0)
            return false;
    }

    // if sum is 0 after processing -> balance string
    return sum == 0;
}

int main()
{
    string s = "xxyyxy";
    cout << findPattern(s);
}