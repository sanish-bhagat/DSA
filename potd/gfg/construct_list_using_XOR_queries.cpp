#include <bits/stdc++.h>
using namespace std;

//! TC is O(q * log q)
//! SC is O(1)

vector<int> constructList(vector<vector<int>> &queries)
{
    // initialise the arr[] with 0
    vector<int> arr = {0};

    // using lazy XOR technique
    int xr = 0;

    for (auto q : queries)
    {
        // push the curr element with the XOR
        if (q[0] == 0)
        {
            arr.push_back(q[1] ^ xr);
        }

        // update the value of the XOR
        else
        {
            xr ^= q[1];
        }
    }

    // XOR all elements of the arr[], to gain its actual state
    for (int &x : arr)
        x ^= xr;

    // sort the final arr[]
    sort(arr.begin(), arr.end());

    return arr;
}

int main()
{
    vector<vector<int>> queries = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}};

    vector<int> res = constructList(queries);
}