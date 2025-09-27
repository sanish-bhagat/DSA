#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int prod = 1;

        for (int j = 0; j < n; j++)
        {

            if (i == j)
                continue;

            prod *= arr[j];
        }

        res.push_back(prod);
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}