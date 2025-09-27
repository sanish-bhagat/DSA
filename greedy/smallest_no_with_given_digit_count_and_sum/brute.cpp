#include <bits/stdc++.h>
using namespace std;

//! TC is O(d * (1o ^ d))
//! SC is O(1)

string smallestNumber(int s, int d)
{
    int start = pow(10, d - 1);
    int end = pow(10, d) - 1;

    for (int num = start; num <= end; num++)
    {
        int sum = 0, x = num;

        // keek checking the curr sum of digit
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }

        // if curr sum of digits of num becomes equal to given sum, then return the num
        if (sum == s)
            return to_string(num);
    }

    return "1";
}

int main()
{

    int s = 9, d = 2;

    cout << smallestNumber(s, d) << endl;
    return 0;
}