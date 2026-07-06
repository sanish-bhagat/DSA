#include <bits/stdc++.h>
using namespace std;

//! TC is O(n*logn + m*logm)
//! SC is O(1)

int maxPathSum(vector<int> &a, vector<int> &b)
{
    // sort in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size(), m = b.size();

    // ptrs to traverse the arr's
    int i = 0, j = 0;

    int res = 0, sum1 = 0, sum2 = 0;

    while (i < n && j < m)
    {
        // a[] element is smaller, include in sum and move ptr forward
        if (a[i] < b[j])
            sum1 += a[i++];

        // b[] element is smaller, include in sum and move ptr forward
        else if (a[i] > b[j])
            sum2 += b[j++];

        // elements are same, can switch path
        else
        {
            // take the max running sum till now from both the arr's
            res += max(sum1, sum2) + a[i];

            // reset for further elements
            sum1 = 0, sum2 = 0;
            i++, j++;
        }
    }

    // include left out elements, if any
    while (i < n)
        sum1 += a[i++];

    while (j < m)
        sum2 += b[j++];

    // include the max of both the running sum
    res += max(sum1, sum2);

    return res;
}

int main()
{
    vector<int> a = {2, 3, 7, 10, 12, 15, 30, 34};
    vector<int> b = {1, 5, 7, 8, 10, 15, 16, 19};

    cout << maxPathSum(a, b);
    return 0;
}