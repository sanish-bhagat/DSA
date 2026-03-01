//? Ques

// An e-commerce platform lists product prices sorted in increasing order.

// A customer wants to buy three products such that total cost equals exactly B.

// Return true if possible.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

// three sum
bool isPossible(vector<int> &prices, int b)
{
    int n = prices.size();

    // fix i
    for (int i = 0; i < n - 2; i++)
    {
        // skip duplicates
        if (i > 0 && prices[i] == prices[i - 1])
            continue;

        // apply two ptrs
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            // curr triplet sum
            int sum = prices[i] + prices[j] + prices[k];

            // valid triplet
            if (sum == b)
                return true;

            // move k for smaller elements
            else if (sum > b)
                k--;

            // move j for larger elements
            else
                j++;
        }
    }

    // no valid triplet found
    return false;
}

int main()
{
    int b = 16;
    vector<int> prices = {1, 2, 4, 6, 8, 10};
    cout << isPossible(prices, b);
}