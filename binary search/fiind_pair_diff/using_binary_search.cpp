#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * log n)
//! SC is O(1)

bool findPair(vector<int> &arr, int x)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int left = 0, right = 1;

    while (right < n)
    {
        int currDiff = arr[right] - arr[left];

        if (currDiff == x)
            return true;

        else if (currDiff < x)
            right++;

        else
        {
            left++;

            if (left == right)
                right++;
        }
    }

    return false;
}

int main()
{

    vector<int> v = {1, 8, 30, 40, 100};
    cout << findPair(v, 60);
}