#include <bits/stdc++.h>
using namespace std;

//! TC is O(n! * n * log n!)
//! SC is O(n!)

void permutations(vector<int> &arr, vector<vector<int>> &res, int ind)
{

    // base case
    if (ind == arr.size() - 1)
    {
        res.push_back(arr);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {

        swap(arr[ind], arr[i]);

        // rescursicve call
        permutations(arr, res, ind + 1);

        // backtracking
        swap(arr[ind], arr[i]);
    }
}

void nextPermutation(vector<int> &arr)
{
    vector<vector<int>> res;
    permutations(arr, res, 0);
    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == arr)
        {
            if (i < res.size() - 1)
            {
                arr = res[i + 1];
            }

            if (i == res.size() - 1)
            {
                arr = res[0];
            }

            break;
        }
    }
}

int main()
{
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);
  
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}