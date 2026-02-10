#include <bits/stdc++.h>
using namespace std;

// func to tell whether KOKO can eat all bananas by eating in the curr speed
bool check(vector<int> &arr, int speed, int k)
{
    int totalHours = 0;

    for (int i = 0; i < arr.size(); i++)

        // always take the ceil value in the totalHrs count
        totalHours += (arr[i] + speed - 1) / speed;

    // return true if totalHrs needed is within limit
    return totalHours <= k;
}

//! TC is O(n * logm)
//! SC is O(1)

int kokoEat(vector<int> &arr, int k)
{
    // binary search on speed
    int low = 1, high = *max_element(arr.begin(), arr.end());

    int res = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // if this speed satisfies the condn -> move high,
        // as we have to find the min value
        if (check(arr, mid, k))
        {
            res = mid;
            high = mid - 1;
        }

        // condn not satisfies -> move low to check for larger speed
        else
            low = mid + 1;
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 10, 3};
    int k = 4;
    cout << kokoEat(arr, k) << endl;
    return 0;
}