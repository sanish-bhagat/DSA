// A fitness app tracks calories burned per minute.

// You are given an array where each element represents calories burned in that minute.

// Find the maximum calories burned in any continuous window of size k.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! Sc is O(n)

int maxCalories(vector<int> &calories, int k)
{
    // calories burned in 1st k-window
    int windowCal = 0;
    for (int i = 0; i < k; i++)
        windowCal += calories[i];

    int maxCal = windowCal;

    // slide the k-sized window through the calories[]
    for (int i = k; i < calories.size(); i++)
    {
        // include the curr element
        windowCal += calories[i];

        // exclude the out of window element
        windowCal -= calories[i - k];

        // update the max calories burned
        maxCal = max(maxCal, windowCal);
    }

    return maxCal;
}

int main()
{
    vector<int> calories = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxCalories(calories, k);
}