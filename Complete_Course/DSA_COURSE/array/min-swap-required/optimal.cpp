#include <bits/stdc++.h>
using namespace std;

//! TC is O(N)
//! SC is O(1)

int minSwap(int arr[], int n, int k)
{

    int good = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] <= k)
            good++;
    }

    int bad = 0, minSwaps = good;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > k)
            bad++;

        if (i == good - 1)
            minSwaps = min(minSwaps, bad);

        else if (i >= good)
        {

            if (arr[i] > k)
                bad--;

            minSwaps = min(minSwaps, bad);
        }
    }

    return minSwaps;
}

int main()
{
    int arr1[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;

    cout << minSwap(arr1, n, k) << "\n";
    return 0;
}