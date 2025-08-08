#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int calculate(int curr, int n, vector<int> &arr, int k)
{

    // base case : if curr is beyond or at the last word no cost
    if (curr >= n)
        return 0;

    //sum : store the total char in a line
    int sum = 0, ans = INT_MAX;

    for (int i = curr; i < n; i++)
    {

        //add the len og the current word
        sum += arr[i];

        //including spaces within words
        int tot = sum + (i - curr);

        if (tot > k)
            break;

        //if not the last word compute the cost for the nest line
        if (i != n - 1)
        {
            int temp = (k - tot) * (k - tot) + calculate(i + 1, n, arr, k);
            ans = min(ans, temp);
        }

        //last word therefore no cost
        else
        {
            ans = 0;
        }
    }

    return ans;
}

int solveWordWrap(vector<int> arr, int k)
{
    int n = arr.size();
    return calculate(0, n, arr, k);
}

int main()
{
    int k = 6;

    vector<int> arr = {3, 2, 2, 5};
    int res = solveWordWrap(arr, k);
    cout << res << endl;
    return 0;
}