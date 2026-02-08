#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxProduct(vector<int> &arr)
{
    // start from the first element as our curr best state
    // keep track of minProd because -ve * -ve -> may result in a larger +ve
    int currMin = arr[0], currMax = arr[0], maxProd = arr[0];

    // traverse through the elements of the arr[]
    for (int i = 1; i < arr.size(); i++)
    {
        // reverse kadane's algo -> either extend or restart
        int temp = min({arr[i], currMin * arr[i], currMax * arr[i]});

        // kadane's algo -> either extend or restart
        currMax = max({arr[i], currMin * arr[i], currMax * arr[i]});

        // update currMin
        currMin = temp;

        // update the max product of subarray
        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

int main()
{
    vector<int> arr = {6, -3, -10, 0, 2};
    cout << maxProduct(arr);
}