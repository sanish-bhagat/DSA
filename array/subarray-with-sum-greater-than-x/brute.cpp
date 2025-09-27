#include <bits/stdc++.h>
using namespace std;

//? length find krrna h subarray ka jiska sum just greater than x ho

//! TC is O(n * n)
//! SC is O(1)

int smallestSubWithSum(int x, vector<int> &arr)
{

    int n = arr.size();
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        int curr = 0;

        for (int j = i; j < n; j++)
        {

            curr += arr[j];

            if (curr > x)
            {
                res = min(res, j - i + 1);
                break;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 19};
    int x = 51;

    cout << smallestSubWithSum(x, arr);

    return 0;
}