#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

void pushZerosToEnd(vector<int> &arr)
{
    // position for next zero
    int j = 0;

    // move non-zero elements forward
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 3};
    pushZerosToEnd(arr);

    for (int x : arr)
        cout << x << " ";
}