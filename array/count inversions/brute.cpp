#include <bits/stdc++.h>
using namespace std;

// we have to return the total no. of pairs in which the first element should be greater than the second element

// Tc is O(N*N)
// SC is O(1)

int pairCount(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }

    return count;
}

int main()
{
    int arr[4] = {4, 3, 2, 1};

    cout << pairCount(arr, 4);
}