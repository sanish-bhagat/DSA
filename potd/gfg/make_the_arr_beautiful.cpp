#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> makeBeautiful(vector<int> &arr)
{
    // use the res[] as a stack
    vector<int> res;

    // traverse through the arr[] elements
    for (int i = 0; i < arr.size(); i++)
    {
        // keep track of whether to push curr element or not
        bool flag = false;

        if (!res.empty())
        {
            // both adjacent have different signs pop from the res,
            // skip both the elements
            if (res.back() >= 0 && arr[i] < 0)
            {
                res.pop_back();
                flag = true;
            }

            else if (res.back() < 0 && arr[i] >= 0)
            {
                res.pop_back();
                flag = true;
            }
        }

        // push the curr element into the res stack
        if (!flag)
            res.push_back(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {4, 2, -2, 1};
    vector<int> res = makeBeautiful(arr);

    for (int x : res)
        cout << x << " ";
}