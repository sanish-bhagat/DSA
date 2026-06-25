#include <bits/stdc++.h>
using namespace std;

void generateNumbers(int remainingDigits, int currDigit, int currNum, vector<int> &res)
{
    // requireed no. of digits formed
    if (remainingDigits == 0)
    {
        res.push_back(currNum);
        return;
    }

    // choose next digit greater than curr digit
    for (int nextDigit = currDigit + 1; nextDigit <= 9; nextDigit++)
        generateNumbers(remainingDigits - 1, nextDigit, currNum * 10 + nextDigit, res);
}

//! TC is O(C(9, n))
//! SC is O(1)

vector<int> increasingNumbers(int n)
{
    vector<int> res;

    // base case
    if (n == 1)
    {
        for (int i = 0; i <= 9; i++)
            res.push_back(i);

        return res;
    }

    // no valid no. exists for n > 9
    if (n > 9)
        return res;

    // first digit must start from 1
    for (int firstDigit = 1; firstDigit <= 9; firstDigit++)
        generateNumbers(n - 1, firstDigit, firstDigit, res);

    return res;
}

int main()
{
    int n = 2;
    vector<int> res = increasingNumbers(n);

    for (int x : res)
        cout << x << " ";
}