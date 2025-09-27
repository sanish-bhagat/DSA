#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(1)

int minSwap(int arr[], int n, int k)
{

    int cnt = 0;

    //element <= k ka count find krrlo
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            cnt++;
    }

    //agar cnt == 0 mtlb koi bhi swaps needed nhi h
    if (cnt == 0)
        return 0;

    int minSwaps = INT_MAX;

    //subarray of size count ko traverse krr k elements > k count krrlo
    for (int i = 0; i <= n - cnt; i++)
    {

        int bad = 0;

        for (int j = i; j < i + cnt; j++)
        {

            if (arr[j] > k)
                bad++;
        }

        //minSwaps ko update krro
        minSwaps = min(minSwaps, bad);
    }

    return minSwaps;
}

int main()
{
    int arr1[] = {2, 7, 9, 8, 5, 7, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 5;

    cout << minSwap(arr1, n, k) << "\n";
    return 0;
}