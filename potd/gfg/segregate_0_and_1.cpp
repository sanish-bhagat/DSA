#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

void segregate0and1(vector<int> &arr)
{
    int left = 0;

    // use two ptrs, one to traverse the arr[], and one to know the position
    // for the swap
    for (int right = 0; right < arr.size(); right++)
    {
        // swap needed
        if (arr[right] == 0)
            swap(arr[left++], arr[right]);
    }
}

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    segregate0and1(arr);

    for (int x : arr)
        cout << x << " ";
}