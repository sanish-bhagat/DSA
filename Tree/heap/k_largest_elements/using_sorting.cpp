#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

vector<int> kLargest(vector<int> arr, int k)
{
    // sort the arr in decreasing order
    sort(arr.begin(), arr.end(), greater<int>());

    // push the first k elements of the sorted array
    vector<int> res(arr.begin(), arr.begin() + k);

    return res;
}

int main()
{
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> res = kLargest(arr, k);
    for (int ele : res)
        cout << ele << " ";

    return 0;
}