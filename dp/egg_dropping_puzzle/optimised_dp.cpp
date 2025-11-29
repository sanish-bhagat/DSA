#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(n)

int eggDrop(int n, int k)
{
    // 1d dp[]
    vector<int> dp(n + 1, 0);

    // count the no. of moves
    int cnt = 0;

    // process until count of floor is less than k
    while (dp[n] < k)
    {
        // increment the move count
        cnt++;

        // traverse for each egg
        for (int i = n; i > 0; i--)
            dp[i] += 1 + dp[i - 1];
    }

    // return the moves required to reach the critical floor
    return cnt;
}

int main()
{
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}