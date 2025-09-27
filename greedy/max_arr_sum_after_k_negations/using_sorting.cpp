#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

long long int maximizeSum(vector<int> &arr, int k)
{
    int n = arr.size();

    // sort the given arr[]
    sort(arr.begin(), arr.end());

    // perform modifcations on -ve element to make them +ve
    for (int i = 0; i < n && k > 0 && arr[i] < 0; i++)
    {
        arr[i] *= -1;
        k--;
    }

    // If k > 1, we can repeatedly negate
    // the same value even times, so its
    // value will remain the same.
    k %= 2;

    // find the sum of the modified arr[]
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // if no modifactions is to be done, then return the calculated sum
    if (k == 0)
        return sum;

    // else if k == 1, find the min element and negate it
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    // subtract min-element 2 times, inorder to first remove the min value from the sum and
    // then add the negated value to the sum
    return sum - 2 * arr[minIndex];
}

int main()
{
    vector<int> arr = {-2, -3, 5, -1, 2};
    int k = 4;
    cout << maximizeSum(arr, k);
    return 0;
}