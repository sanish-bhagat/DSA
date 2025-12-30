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

int countRec(int i, int j, bool req, string &s)
{
    // base case: single operand(T/F) -> return true if T else 0
    if (i == j)
        return (req == (s[i] == 'T')) ? 1 : 0;

    int ways = 0;

    // partition the string at operator positions -> operator lies at odd indices
    for (int k = i + 1; k < j; k += 2)
    {
        // count ways for left and right sub-expressions
        int leftTrue = countRec(i, k - 1, true, s);
        int leftFalse = countRec(i, k - 1, false, s);
        int rightTrue = countRec(k + 1, j, true, s);
        int rightFalse = countRec(k + 1, j, false, s);

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

//! TC is O(2 ^ n)
//! SC is O(n * n)

int countWays(string &s)
{
    int n = s.size();
    return countRec(0, n - 1, true, s);
}

int main()
{
    string s = "T|T&F^T";
    cout << countWays(s);
    return 0;
}