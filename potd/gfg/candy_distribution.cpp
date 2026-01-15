#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minCandy(vector<int> &arr)
{
    int n = arr.size();

    // each child gets atleast 1 candy
    vector<int> candies(n, 1);

    // 1st pass: left -> right
    for (int i = 1; i < n; i++)
    {
        // give the curr child more candies if it has more rating than its left neighbor
        if (arr[i] > arr[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    // 2nd pass: right -> left
    for (int i = n - 2; i >= 0; i--)
    {
        // give the curr child more candies if it has more rating than its right neighbor,
        // without breaking the left-side condition
        if (arr[i] > arr[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    // return the total min candies required to distribute to the children
    return accumulate(candies.begin(), candies.end(), 0);
}

int main()
{
    vector<int> arr = {1, 0, 2};
    cout << minCandy(arr);
}