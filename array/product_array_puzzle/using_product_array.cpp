#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    int zeros = 0, idx = -1, prod = 1;
    vector<int> res(n, 0);

    //zeros count krro and track their index
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
            idx = i;
        }

        else
        {
            prod *= arr[i];
        }
    }

    //if no zero then calculate the prod for all elements
    if (zeros == 0)
    {
        for (int i = 0; i < n; i++)
            res[i] = prod / arr[i];
    }

    //if one zero hoga tab bass zero wale index pr value set krrdo
    else if (zeros == 1)
        res[idx] = prod;

    return res;
}

int main()
{
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}