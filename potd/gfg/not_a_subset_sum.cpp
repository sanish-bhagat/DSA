#include <bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &arr)
{

    // sort the arr[]
    sort(arr.begin(), arr.end());

    int res = 1;

    // Traverse the array and increment 'res' if arr[i] is
    // smaller than or equal to 'res'.
    for (int i = 0; i < arr.size() && arr[i] <= res; i++)
        res += arr[i];

    // return the smallest positive integer
    return res;
}

int main()
{
    vector<int> arr = {3, 10, 9, 6, 20, 28};
    cout << findSmallest(arr);
}