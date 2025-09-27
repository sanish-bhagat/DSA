#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

vector<int> arrange(vector<int> &arr, int n)
{
    vector<int> res, rest, ones;

    // separate 1's and other no.s, as
    // 1 ^ anything = 1(so its useless until 1 is the last amplifier)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            ones.push_back(arr[i]);

        else
            rest.push_back(arr[i]);
    }

    // sort the rest no.s in descending order
    sort(rest.begin(), rest.end(), greater<int>());

    // special case: if top two are 2 and 3
    // best order is 2 3 ... not 3 2, because
    // having 2 before 3 (as in 2^(3^X)) makes the exponent huge.
    // having 3 before 2 (as in 3^(2^X)) gives a smaller exponent, even though 3^2 itself looks larger.
    if (rest.size() >= 2 && rest[0] == 3 && rest[1] == 2)
        swap(rest[0], rest[1]);

    // update the res[]
    for (int x : rest)
        res.push_back(x);

    for (int y : ones)
        res.push_back(y);

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res = arrange(arr, n);

    for (int i : res)
        cout << i << " ";
}