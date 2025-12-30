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

int countRec(int i, int j, bool req, string &s, vector<vector<vector<int>>> &memo)
{
    // base case: single operand(T/F) -> return true if T else 0
    if (i == j)
        return (req == (s[i] == 'T')) ? 1 : 0;

    // already computed subproblem
    if (memo[i][j][req] != -1)
        return memo[i][j][req];

    int ways = 0;

    // partition the string at operator positions -> operator lies at odd indices
    for (int k = i + 1; k < j; k += 2)
    {
        // count ways for left and right sub-expressions
        int leftTrue = countRec(i, k - 1, true, s, memo);
        int leftFalse = countRec(i, k - 1, false, s, memo);
        int rightTrue = countRec(k + 1, j, true, s, memo);
        int rightFalse = countRec(k + 1, j, false, s, memo);

        // combine the total ways based on operator on position k
        if (evaluate(true, true, s[k]) == req)
            ways += leftTrue * rightTrue;

        if (evaluate(true, false, s[k]) == req)
            ways += leftTrue * rightFalse;

        if (evaluate(false, true, s[k]) == req)
            ways += leftFalse * rightTrue;

        if (evaluate(false, false, s[k]) == req)
            ways += leftFalse * rightFalse;
    }

    return ways;
}

//! TC is O(n ^ 3)
//! SC is O(n * n)

int countWays(string &s)
{
    int n = s.size();

    // 3d memo[]
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));

    return countRec(0, n - 1, true, s, memo);
}

int main()
{
    string s = "T|T&F^T";
    cout << countWays(s);
    return 0;
}