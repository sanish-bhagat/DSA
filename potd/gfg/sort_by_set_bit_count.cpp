#include <bits/stdc++.h>
using namespace std;

// count no. of set bits
int countBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += (n & 1);
        n = n >> 1;
    }

    return cnt;
}

//! TC is O(n)
//! SC is O(n)

vector<int> sortBySetBitCount(vector<int> &arr)
{
    int n = arr.size();

    // 2d matrix, stores elements having i bits
    vector<vector<int>> count(32);

    // traverse through the elements and store in the matrix
    for (int i = 0; i < n; i++)
    {
        int setBits = countBits(arr[i]);
        count[setBits].push_back(arr[i]);
    }

    // build the res[] in descending order
    vector<int> res;
    for (int i = 31; i >= 0; i--)
    {
        for (int k = 0; k < count[i].size(); k++)
            res.push_back(count[i][k]);
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};

    vector<int> res = sortBySetBitCount(arr);
    for (int x : res)
        cout << x << " ";
}