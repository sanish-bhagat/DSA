#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool subarraySum(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    unordered_set<int> sumSet;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
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