#include <bits/stdc++.h>
using namespace std;

// evaluate the boolean value of the operands and operator
bool evaluate(bool left, bool right, char op)
{
    if (op == '&')
        return left & right;

    if (op == '|')
        return left | right;

    return left ^ right;
}

//! TC is O(n ^ 3)
//! SC is O(n * n)

int countWays(string &s)
{
    int n = s.size();

    // 3d memo[] -> stores the no. of ways the sub-expression evaluates to T or F
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    // single operand subexpressions
    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = (s[i] == 'T');
        dp[i][i][0] = (s[i] == 'F');
    }

    // itertate over different sub-expression lengths
    for (int len = 2; len < n; len += 2)
    {
        for (int i = 0; i < n - len; i += 2)
        {
            int j = i + len;

            // reset values for curr sub-expressions
            dp[i][j][0] = dp[i][j][1] = 0;

            // iterate through different operator positions
            for (int k = i + 1; k < j; k += 2)
            {
                char op = s[k];
                int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0];
                int rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];

                // combine the total ways that gives 'True' based on operator on position k
                if (evaluate(true, true, op))
                    dp[i][j][1] += leftTrue * rightTrue;
                if (evaluate(true, false, op))
                    dp[i][j][1] += leftTrue * rightFalse;
                if (evaluate(false, true, op))
                    dp[i][j][1] += leftFalse * rightTrue;
                if (evaluate(false, false, op))
                    dp[i][j][1] += leftFalse * rightFalse;

                // combine the total ways that gives 'False' based on operator on position k
                if (!evaluate(true, true, op))
                    dp[i][j][0] += leftTrue * rightTrue;
                if (!evaluate(true, false, op))
                    dp[i][j][0] += leftTrue * rightFalse;
                if (!evaluate(false, true, op))
                    dp[i][j][0] += leftFalse * rightTrue;
                if (!evaluate(false, false, op))
                    dp[i][j][0] += leftFalse * rightFalse;
            }
        }
    }

    // return the total ways to make the entire expression True
    return dp[0][n - 1][1];
}

int main()
{
    string s = "T|T&F^T";
    cout << countWays(s);
    return 0;
}