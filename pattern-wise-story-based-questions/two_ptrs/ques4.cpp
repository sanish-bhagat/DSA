//? Ques

// An airport scanner records security levels of passengers entering a zone.

// The levels are sorted in ascending order.

// You must remove duplicates in-place such that each level appears only once.

// Return the number of unique levels.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int uniqueLevels(vector<int> &levels)
{
    int left = 0;

    for (int right = 1; right < levels.size(); right++)
    {
        // move left ptr if unique elements are encountered
        if (levels[left] != levels[right])
        {
            left++;
            levels[left] = levels[right];
        }
    }

    // total unique elements
    return left + 1;
}

int main()
{
    vector<int> levels = {1, 1, 2, 2, 2, 3, 4, 4};
    cout << uniqueLevels(levels);
}