#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int findWays(int n)
{
    // length is odd -> ans is 0
    if (n % 2 == 1)
        return 0;

    long long res = 1;

    // no of pairs of pairs of () required
    int k = n / 2;

    // use Catalan Formula to calculate
    for (int i = 0; i < k; i++)
        res = res * (2 * k - i) / (i + 1);

    // divide the res by (k + 1) -> gives no. of valid parantheses
    res /= (k + 1);

    // valid no. of parantheses
    return res;
}

int main()
{
    int n = 6;
    cout << findWays(n);
}