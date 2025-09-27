#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! Sc is O(1)

int maxSubarrayProd(vector<int> &arr)
{
    int n = arr.size();

    int currMax = arr[0], currMin = arr[0], maxProd = arr[0];

    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * currMin, arr[i] * currMax});
        
        currMin = min({arr[i], arr[i] * currMin, arr[i] * currMax});

        currMax = temp;

        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

int main()
{
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << maxSubarrayProd(arr);
    return 0;
}