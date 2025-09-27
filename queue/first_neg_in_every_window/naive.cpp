#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(1)

vector<int> firstNegInt(vector<int> &arr, int k)
{
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i <= (n - k); i++)
    {
        bool found = false;
        for (int j = 0; j < k; j++)
        {
            if (arr[i + j] < 0)
            {
                // if -ve element is found in the window push it and break the loop
                res.push_back(arr[i + j]);
                found = true;
                break;
            }
        }

        // if not found any -ve element then push 0
        if (!found)
            res.push_back(0);
    }

    return res;
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};

    int k = 3;
    vector<int> res = firstNegInt(arr, k);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i < res.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    return 0;
}