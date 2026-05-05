#include <bits/stdc++.h>
using namespace std;

long long sumXOR(vector<int> &arr)
{
    long long sum = 0;

    // process for every bit position
    for (int i = 0; i < 32; i++)
    {
        // count zeros and ones for the binary no.
        int oneCnt = 0, zeroCnt = 0;

        // traverse through every element
        for (int j = 0; j < arr.size(); j++)
        {
            // if the bit at position i is set -> increment the set bit count
            if ((arr[j] >> i) & 1)
                oneCnt++;

            // else increment the unset bit count
            else
                zeroCnt++;
        }

        // add the curr individual bit sum
        sum += (long)oneCnt * zeroCnt * (1 << i);
    }

    return sum;
}

int main()
{
    vector<int> arr = {5, 9, 7, 6};
    cout << sumXOR(arr);
}