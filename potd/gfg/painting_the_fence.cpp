#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countWays(int n, int k)
{
    // base case
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    // keep track of the previous states,
    // initialise with the values for 1 and 2 fences
    int prev2 = k, prev1 = k * k;

    // iterate through all the fences
    for (int i = 3; i <= n; i++)
    {
        // ways to paint curr fence
        int curr = prev1 * (k - 1) + prev2 * (k - 1);

        // update the states
        prev2 = prev1;
        prev1 = curr;
    }

    // return the no. of ways to paint n fences using k colors
    return prev1;
}

int main()
{
    int n = 5, k = 2;

    cout << countWays(n, k);
}