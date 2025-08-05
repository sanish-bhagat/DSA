#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! SC is O(1)

int maxPathSum(vector<int> &a, vector<int> &b)
{

    int n = a.size(), m = b.size();
    int sum1 = 0, sum2 = 0, result = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {

        if (a[i] < b[j])
            sum1 += a[i++];

        else if (a[i] > b[j])
            sum2 += b[j++];

        else
        {   // intersection point found
            result += max(sum1, sum2) + a[i]; // add max of both sum and common element
            sum1 = 0;
            sum2 = 0;
            i++, j++;
        }
    }

    while (i < n)
        sum1 += a[i++];

    while (j < m)
        sum2 += b[j++];

    result += max(sum1, sum2);  //add the max of remaining sums

    return result;
}

int main()
{
    vector<int> first = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
    vector<int> second = {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};

    cout << "Maximum path sum: " << maxPathSum(first, second) << endl;
    return 0;
}