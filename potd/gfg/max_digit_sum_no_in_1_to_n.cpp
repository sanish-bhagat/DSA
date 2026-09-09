#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(log n)

int findMax(int n)
{
    // Convert n into a string to easily access its digits
    string s = to_string(n);
    int d = s.size();

    // Calculate the digit sum of n
    int totalSum = 0;
    for (char c : s)
        totalSum += c - '0';

    // Initially, n itself is the answer
    int ans = n;
    int bestSum = totalSum;

    // p represents the place value of the current digit
    long long p = 1;

    // Sum of the current digit and all digits to its right
    int suffixSum = 0;

    // Traverse digits from right to left
    for (int i = d - 1; i >= 0; i--)
    {
        int digit = s[i] - '0';

        // Include the current digit in the suffix sum
        suffixSum += digit;

        // We can decrease the current digit only if it is greater than 0
        if (digit > 0)
        {

            // Form the candidate:
            // Keep digits to the left unchanged,
            // decrease the current digit by 1,
            // and make all digits to its right 9.
            long long cand = (n / (p * 10)) * (p * 10);
            cand += (digit - 1) * p;
            cand += p - 1;

            // Number of digits to the right of the current digit
            int digitsRight = d - i - 1;

            // Calculate the candidate's digit sum in O(1).
            // Remove the current digit and suffix from totalSum,
            // add the decreased current digit,
            // and add 9 for every digit on the right.
            int curSum = totalSum - suffixSum + (digit - 1) + 9 * digitsRight;

            // Update the answer if this candidate has:
            // 1. A larger digit sum, or
            // 2. The same digit sum but a larger value
            if (curSum > bestSum || (curSum == bestSum && cand > ans))
            {
                bestSum = curSum;
                ans = (int)cand;
            }
        }

        // Move to the next digit position
        p *= 10;
    }

    return ans;
}

int main()
{
    int n = 521;
    cout << findMax(n) << endl;

    return 0;
}