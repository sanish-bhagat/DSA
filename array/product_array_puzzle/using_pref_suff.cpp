#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pref(n), suff(n), res(n);

    // pref product
    pref[0] = 1;
    for (int i = 1; i < n; i++)
        pref[i] = arr[i - 1] * pref[i - 1];

    // suff product
    suff[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
        suff[j] = arr[j + 1] * suff[j + 1];

    for (int i = 0; i < n; i++)
        res[i] = pref[i] * suff[i];

    return res;
}

int main()
{
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}