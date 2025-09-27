#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(k)

int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0;
    multiset<pair<int, int>> ms;
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        ms.insert({arr[j], j});

        int windowSize = j - i + 1;

        if (windowSize == k)
        {
            int mini = ms.begin()->first; // mutiset inserts element in ascending order
            int maxi = ms.rbegin()->first;

            sum += maxi + mini;

            // erase the begining element of the multiset
            ms.erase({arr[i], i});

            // increment the back ptr
            i++;
        }
        j++; // always increment the front ptr
    }

    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, N, k);
    return 0;
}
