#include <bits/stdc++.h>
using namespace std;

int countTripletsLessThan(vector<int> &arr, int val)
{
    int n = arr.size();

    // sort the input array.
    sort(arr.begin(), arr.end());

    // Initialize result
    int ans = 0;

    int j, k;

    // to store sum
    int sum;

    // Fix the first element
    for (int i = 0; i < n - 2; i++)
    {

        // Initialize other two elements as
        // corner elements of subarray arr[j+1..k]
        j = i + 1;
        k = n - 1;

        // Use Meet in the Middle concept.
        while (j < k)
        {
            sum = arr[i] + arr[j] + arr[k];

            // If sum of current triplet
            // is greater, then to reduce it
            // decrease k.
            if (sum > val)
                k--;

            // If sum is less than or equal
            // to given value, then add
            // possible triplets (k-j) to result.
            else
            {
                ans += (k - j);
                j++;
            }
        }
    }

    return ans;
}

//! TC is O(n * n)
//! SC is O(1)

int countTriplets(vector<int> &arr, int l, int r)
{

    // to store count of triplets.
    int res;

    // Find count of triplets having sum less
    // than or equal to r and subtract count
    // of triplets having sum less than or
    // equal to l-1.
    res = countTripletsLessThan(arr, r) -
          countTripletsLessThan(arr, l - 1);

    return res;
}

// Driver Code
int main()
{
    vector<int> arr = {2, 7, 5, 3, 8, 4, 1, 9};

    int l = 8, r = 16;

    cout << countTriplets(arr, l, r) << endl;

    return 0;
}