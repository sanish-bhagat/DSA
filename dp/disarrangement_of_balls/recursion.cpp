#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int disarrange(int n)
{
    // base case: only one position -> no possible disarrangement possible
    if (n == 1)
        return 0;

    // base case: two positions -> can swap them to make aa disarrangement
    if (n == 2)
        return 1;

    // case1: two elements swapped positions by each other and are valid possible derangements ->
    // recurse for left out (n - 2) elements
    int placed = disarrange(n - 2);

    // case2: two elements swapped positions by are not valid possible derangements ->
    // recurse for same (n - 1) elements
    int notPlaced = disarrange(n - 1);

    // total ways for n elements where it can go is (n - 1) choices
    return (n - 1) * (placed + notPlaced);
}

int main()
{
    int n = 4;
    cout << disarrange(n);
    return 0;
}