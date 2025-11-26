#include <bits/stdc++.h>
using namespace std;

int countSubsets(int i, int currProduct, int k, vector<int> &arr)
{
    int n = arr.size();

    // base case: all elements processed -> eturn 1 if the current product is less than or equal to k,
    // otherwise return 0
    if (i == n)
        return (currProduct <= k);

    // exclude the curr element
    int exclude = countSubsets(i + 1, currProduct, k, arr);

    int include = 0;

    // include the curr element if the product remains <= k
    if (arr[i] * currProduct <= k)
        include = countSubsets(i + 1, currProduct * arr[i], k, arr);

    // return the total no. of subsets including both cases
    return (include + exclude);
}

//! TC is O(2^n)
//! SC is O(n)

int numOfSubsets(vector<int> &arr, int k)
{
    // return the total count of subsets, excluding the empty set{}
    return countSubsets(0, 1, k, arr) - 1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << numOfSubsets(arr, k);
    return 0;
}