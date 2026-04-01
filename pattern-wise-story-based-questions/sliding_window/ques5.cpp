// A bank monitors transactions.

// Find the number of subarrays whose sum = K.

//! Works only when all the transactions are +ve

//! TC is O(n)
//! SC is O(1)

#include <bits/stdc++.h>
using namespace std;

int noOfSub(vector<int> &transactions, int k)
{
    int cnt = 0;

    int left = 0, sum = 0;

    // slide the window through the arr[]
    for (int right = 0; right < transactions.size(); right++)
    {
        // include the element in the curr window sum
        sum += transactions[right];

        // shrink the window until not valid
        while (sum > k)
        {
            sum -= transactions[left];

            left++;
        }

        // increment the count of the valid subarray
        if (sum == k)
            cnt++;
    }

    return cnt;
}

int main()
{
    vector<int> transactions = {1, 1, 1};
    int k = 2;

    cout << noOfSub(transactions, k);
}