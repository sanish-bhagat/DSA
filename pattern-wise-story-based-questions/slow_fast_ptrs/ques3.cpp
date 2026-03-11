// A network transmits packets labeled from 1..n.

// However, due to a system bug, one packet ID is duplicated, creating a loop in the mapping.

// You are given an array where:

// nums[i] → next packet index

// Find the duplicate packet ID.

#include <bits/stdc++.h>
using namespace std;

int duplicate(vector<int> &nums)
{
    // slow moves 1-step and fst moves 2-step forward
    int slow = nums[0], fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        // cycle detects
        if (slow == fast)
        {

            // move the slow ptr to the start of the packet[] and find the duplicate element
            slow = nums[0];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }

            // return the duplicate element
            return slow;
        }
    } while (slow != fast);

    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << duplicate(nums);
}