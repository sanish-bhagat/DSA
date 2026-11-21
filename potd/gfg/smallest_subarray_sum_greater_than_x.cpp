#include <bits/stdc++.h>
using namespace std;

int smallestSubWithSum(vector<int> &arr, int x)
{
    int minLen = INT_MAX;

    int left = 0, sum = 0;

    // using two ptr technique
    for (int right = 0; right < arr.size(); right++)
    {
        // include the element
        sum += arr[right];

        while (sum > x)
        {
            // update the minLen
            minLen = min(minLen, right - left + 1);

            // exlucde the element from the window
            sum -= arr[left];
            left++;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int x = 51;
    cout << smallestSubWithSum(arr, x);
}