#include <bits/stdc++.h>
using namespace std;

//! TC is O(N)
//! SC is O(1)

int smallestSubWithSum(int x, vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 0, sum = 0, ans = INT_MAX;

    while (j < n)
    {

        // sum find krro subarray ka
        while (j < n && sum <= x)
            sum += arr[j++];

        // agar ye condition fulfill hogya then no subarray exist
        if (j == n && sum <= x)
            break;

        // window ko shrink krro from start
        while (i < j && sum - arr[i] > x)
            sum -= arr[i++];

        // ans update krro
        ans = min(ans, j - i);

        // curr start element remove krro and window shift krrdo
        sum -= arr[i];
        i++;
    }

    if (ans == INT_MAX)
        return 0;

    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 19};
    int x = 51;

    cout << smallestSubWithSum(x, arr);

    return 0;
}