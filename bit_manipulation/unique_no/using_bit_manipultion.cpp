#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> singleNum(vector<int> &arr)
{
    // find XOR of all elements -> so that only unique elements stays(as, a ^ a = 0)
    int xorVal = 0;
    for (int i : arr)
        xorVal ^= i;

    // find the rightmost set bit -> used to separate the two unique no.s
    // -xorVal -> 2's compliment
    xorVal &= -xorVal;

    vector<int> res(2, 0);

    // divide the elements into two grps based on that bit
    for (int num : arr)
    {
        if ((num & xorVal) == 0)
            res[0] ^= num;

        else
            res[1] ^= num;
    }

    // return the res in coorect order
    if (res[0] > res[1])
        swap(res[0], res[1]);

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> ans = singleNum(arr);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}