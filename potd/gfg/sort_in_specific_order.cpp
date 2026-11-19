#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

void sortIt(vector<int> &arr)
{
    int n = arr.size();

    // make the odd elements negative
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
            arr[i] *= -1;
    }

    // sort the elements in ascending order ->
    // odds ones with larger abs value will appear in the front
    sort(arr.begin(), arr.end());

    // reset the negative values
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            arr[i] *= -1;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 5, 4, 7, 10};

    sortIt(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}