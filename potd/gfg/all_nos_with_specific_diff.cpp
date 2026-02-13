#include <bits/stdc++.h>
using namespace std;

// func tells whether the (curr no. - its digit sum) >= d
int isGreater(int val, int d)
{
    int digitSum = 0, temp = val;

    while (temp > 0)
    {
        digitSum += (temp % 10);
        temp /= 10;
    }

    // returns valid no. or not
    return val - digitSum >= d;
}

int getCount(int n, int d)
{
    int mini = n + 1;

    // binary search on no. to find the minimum value for which condn satisfies
    // we find min because if the condn satifies for min then it will also satisfy for no. > mini
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // for mid -> condition satisfies ->
        // this may be our min value, move high to check for more minimum value
        if (isGreater(mid, d))
        {
            mini = mid;
            high = mid - 1;
        }

        // condn not satisfies -> move low for higher no. values
        else
            low = mid + 1;
    }

    // return the total count of the valid no.s
    return n - mini + 1;
}

int main()
{
    int n = 13, d = 2;
    cout << getCount(n, d);

    return 0;
}