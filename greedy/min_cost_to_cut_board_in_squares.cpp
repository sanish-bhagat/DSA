#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn + m * logm)
//! SC is O(1)

int minimumCostOfBreaking(int m, int n, vector<int> &x, vector<int> &y)
{
    // sort the cost arrays
    sort(x.begin(), x.end()); // vertical cost[]
    sort(y.begin(), y.end()); // horizontal cost[]

    // traverse from the last of the [] to get the largest cost first
    int i = x.size() - 1, j = y.size() - 1;
    int totalCost = 0;

    // track no. of horizontal and vertical pieces
    int hCount = 1, vCount = 1;

    // traverse the cost[]'s
    while (i >= 0 && j >= 0)
    {
        // if vertical cost is largest
        if (x[i] > y[j])
        {
            // curr cost = vertical cost * no. of horizonatl pieces
            totalCost += x[i] * hCount;
            vCount++; // increase the no. of vertical pieces
            i--;
        }
        else
        {
            // curr cost = horizontal cost * no. of vertical pieces
            totalCost += y[j] * vCount;
            hCount++; // increase the no. of horizontal pieces
            j--;
        }
    }

    // traverse the leftout elements
    while (i >= 0)
    {
        totalCost += x[i] * hCount;
        vCount++;
        i--;
    }

    while (j >= 0)
    {
        totalCost += y[j] * vCount;
        hCount++;
        j--;
    }

    return totalCost;
}

int main()
{

    int m = 6, n = 4;
    vector<int> x = {2, 1, 3, 1, 4};
    vector<int> y = {4, 1, 2};

    cout << minimumCostOfBreaking(m, n, x, y) << endl;
    return 0;
}