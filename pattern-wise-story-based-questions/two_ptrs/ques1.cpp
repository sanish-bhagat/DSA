//? Ques:
// At a tech conference, guests are seated in a row.
// Each guest has a badge number (array of integers, sorted in non-decreasing order).

// The organizers want to find two guests whose badge numbers add up exactly to a given VIP code K.

// Return their seat positions (1-indexed).
// There is guaranteed to be exactly one such pair.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

// pair sum == k
vector<int> sumUpToK(vector<int> &badges, int k)
{
    int left = 0, right = badges.size() - 1;

    while (left < right)
    {
        // curr pair sum
        int sum = badges[left] + badges[right];

        // curr pair is valid -> return 1-based index
        if (sum == k)
            return {left + 1, right + 1};

        // move right to smaller elements
        else if (sum > k)
            right--;

        // move left to larger elements
        else
            left++;
    }

    // no valid pair
    return {-1, -1};
}

int main()
{
    vector<int> badges = {2, 4, 7, 11, 15};
    int k = 15;

    vector<int> res = sumUpToK(badges, k);

    for (int x : res)
        cout << x << " ";
}