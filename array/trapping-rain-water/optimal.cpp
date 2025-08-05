#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! Sc is O(1)

int maxWater(vector<int> &arr)
{

    int n = arr.size();
    int res = 0;

    int left = 1, right = n - 2;
    int lMax = arr[left - 1], rMax = arr[right + 1];

    while (left <= right)
    {

        if (lMax <= rMax)
        {
            res += max(0, lMax - arr[left]);

            lMax = max(lMax, arr[left]);

            left++;
        }

        else
        {

            res += max(0, rMax - arr[right]);

            rMax = max(rMax, arr[right]);

            right--;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
    return 0;
}