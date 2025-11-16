#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countWays(int n, int k)
{
    // base cases
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    // known values for n == 1 and n == 2
    // keep track of only the last two values 
    int prev1 = k, prev2 = k * k;

    // iterate and compute the total ways
    for (int i = 3; i <= n; i++)
    {
        // ways to paint the fence ->
        // either last post is of different color compared to second last one
        // or last two posts are of same color
        int curr = prev1 * (k - 1) + prev2 * (k - 1);

        // keep track of the last two updated values
        prev2 = prev1;
        prev1 = curr;
    }

    // return the total count of ways
    return prev1;
}

int main()
{

    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}