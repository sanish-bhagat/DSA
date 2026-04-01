#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countStrings(int n)
{
    // base case
    if (n == 1)
        return 2;

    if (n == 2)
        return 3;

    // keep track of the previous states
    int prev1 = 3, prev2 = 2;

    // iterate from right to left
    for (int i = n - 3; i >= 0; i--)
    {
        // curr state -> comes from (i + 1) and (i + 2) state
        int curr = prev1 + prev2;

        // update the states
        prev2 = prev1;
        prev1 = curr;
    }

    // return the total valid combinations possible
    return prev1;
}

int main()
{
    int n = 4;
    cout << countStrings(n);
}