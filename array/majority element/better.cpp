#include <bits/stdc++.h>
using namespace std;

// TC is O(N) + O(N*logN)
// SC is O(N) only if array conatins all the unique elements

int majorityElement(int arr[], int n)
{
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << majorityElement(arr, n);
}