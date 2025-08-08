#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k * k)
//! SC is O(k)

vector<int> findSmallestRange(vector<vector<int>> &arr)
{
    int k = arr.size();

    vector<int> ptr(k, 0);
    vector<int> smallest = {0, INT_MAX};

    while (true)
    {
        int currMin = INT_MAX, currMax = INT_MIN, minIndex = -1;

        for (int i = 0; i < k; i++)
        {
            int val = arr[i][ptr[i]];

            if (val < currMin)
            {
                currMin = val;
                minIndex = i;
            }

            if (val > currMax)
                currMax = val;
        }

        if (currMax - currMin < smallest[1] - smallest[0])
        {
            smallest[1] = currMax;
            smallest[0] = currMin;
        }

        ptr[minIndex]++;

        if (ptr[minIndex] == arr[minIndex].size())
            break;
    }

    return smallest;
}

int main()
{

    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};

    vector<int> res = findSmallestRange(arr);

    cout << res[0] << " " << res[1];

    return 0;
}