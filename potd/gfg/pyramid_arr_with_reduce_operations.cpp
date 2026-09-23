#include <bits/stdc++.h>
using namespace std;

int formPyramid(vector<int> &arr)
{
    int n = arr.size();

    // total height of all stones
    int totalSum = 0;
    for (int x : arr)
        totalSum += x;

    // for arrays of size 1 or 2, the only possible pyramid
    // has height 1, so the remaining stones must be reduced to 0
    if (n <= 2)
        return totalSum - 1;

    vector<int> left(n), right(n);

    // left[i] = Maximum possible pyramid height at index i
    // considering only the left side
    left[0] = 1;
    for (int i = 1; i < n; i++)
        left[i] = min(left[i - 1] + 1, arr[i]);

    // right[i] = Maximum possible pyramid height at index i
    // considering only the right side
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        right[i] = min(right[i + 1] + 1, arr[i]);

    int minCost = INT_MAX;

    // try every index as the peak of pyramid
    for (int i = 0; i < n; i++)
    {
        // the peak height is limited by both the left and right constraints
        int peakHeight = min(left[i], right[i]);

        // a pyramid of height h has a total sum of h^2
        int pyramidSum = peakHeight * peakHeight;

        // cost = original total height - height of the constructed pyramid
        minCost = min(minCost, totalSum - pyramidSum);
    }

    return minCost;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 1};

    cout << formPyramid(arr) << endl;

    return 0;
}