#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(n * k)

int eggDrop(int n, int k)
{
    // 2d dp[]
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    // count no. of moves
    int cnt = 0;

    // while the no. of floors is less than k
    while (dp[cnt][n] < k)
    {
        // increment the floor count
        cnt++;

        // traverse through each egg: either egg breaks or does not break
        // move to above or lower floor according to the cases
        for (int i = 1; i <= n; i++)
            dp[cnt][i] = 1 + dp[cnt - 1][i - 1] + dp[cnt - 1][i];
    }

    return cnt;
}

int main()
{
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}