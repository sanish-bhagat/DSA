#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDiff(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // sort the given arrs[]
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int bestDiff = INT_MAX, bestSum = INT_MAX;

    // 3ptrs, each at start of every arr[]
    int i = 0, j = 0, k = 0;

    int x, y, z;

    // traverse the arr[] using the 3 ptrs
    while (i < a.size() && j < b.size() && k < c.size())
    {
        // min and max values in curr triplet
        int mn = min({a[i], b[j], c[k]});
        int mx = max({a[i], b[j], c[k]});

        // curr diff of the max and min values
        int currDiff = mx - mn;

        // sum of the curr triplet
        int sum = a[i] + b[j] + c[k];

        // founded a better diff || same diff but smalleer sum -> update values
        if (currDiff < bestDiff || currDiff == bestDiff && sum < bestSum)
        {
            bestDiff = currDiff;
            bestSum = sum;

            // x -> max value, y = middle value, z = min value
            x = mx, y = sum - (mx + mn), z = mn;
        }

        // move the ptr of min element
        if (a[i] == mn)
            i++;

        else if (b[j] == mn)
            j++;

        else
            k++;
    }

    // return the res(already in decreasing order)
    return {x, y, z};
}

int main()
{
    vector<int> a = {5, 2, 8}, b = {10, 7, 12}, c = {9, 14, 6};

    vector<int> res = smallestDiff(a, b, c);

    for (int x : res)
        cout << x << " ";
}