#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * k)
//! SC is O(1)

int SumOfKsubArray(vector<int> arr, int n, int k)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // to track the length of the subarray
        int len = 0;

        for (int j = i; j < n; j++)
        {
            len++;

            if (len == k)
            {
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (int l = i; l <= j; l++)
                {
                    maxi = max(maxi, arr[l]);
                    mini = min(mini, arr[l]);
                }

                sum += maxi + mini;
            }
        }
    }

    return sum;
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int N = arr.size();
    int k = 4;
    cout << SumOfKsubArray(arr, N, k);
    return 0;
}
