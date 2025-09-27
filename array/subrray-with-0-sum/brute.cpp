#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

bool subarraySum(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];

        if (sum == 0)
            return true;

        for (int j = i + 1; j < n; j++)
        {
            sum += arr[j];

            if (sum == 0)
                return true;
        }
    }

    return false;
}

int main()
{
    vector<int> v = {4, 2, -3, 1, 6};

    if (subarraySum(v))
    {
        cout << "Subarray exist with sum 0";
    }

    else
    {
        cout << "No subarray exist with sum 0";
    }
}