//? Ques

// A startup tracks daily net gain/loss.
// They want to check if there exists a continuous segment of days where the total gain equals exactly zero.

// Return true if such segment exists.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool isGainZero(vector<int> &tracks)
{
    // set to store sum ending at every index i
    unordered_set<int> seen;

    int sum = 0;

    for(int i = 0; i < tracks.size(); i++)
    {
        // running sum
        sum += tracks[i];

        // running sum == 0 || curr sum is already seen previously -> return true
        if (sum == 0 || seen.count(sum))
            return true;

        // store the curr sum in the set
        seen.insert(sum);
    }

    return false;
}

int main()
{
    vector<int> tracks = {4, -2, -2, 5, -5};
    cout << isGainZero(tracks);
}