#include <bits/stdc++.h>
using namespace std;

//! TC is O(maxi * maxi)
//! SC is O(maxi)

bool pythagoreanTriplet(vector<int> &arr)
{
    // find the max element in the given arr[]
    int maxi = *max_element(arr.begin(), arr.end());

    // visited[]
    vector<bool> visited(maxi + 1, false);

    // mark the elements that are present in the given arr[]
    for (int x : arr)
        visited[x] = true;

    // iterate for all possible a
    for (int a = 1; a < maxi + 1; a++)
    {
        // a not present in the arr[]
        if (!visited[a])
            continue;

        // iterate for all possible b
        for (int b = 1; b < maxi + 1; b++)
        {
            // b not present in the arr[]
            if (!visited[b])
                continue;

            // compute the expected value of c for this pair
            int c = sqrt(a * a + b * b);

            // c^2 is not a perfect square or c exceeds the max value -> invalid c
            if ((c * c) != (a * a + b * b) || c > maxi)
                continue;

            // c is present in the given arr[] -> valid c -> we have found the triplet
            if (visited[c])
                return true;
        }
    }

    // no triplet is possible
    return false;
}

int main()
{
    vector<int> arr = {3, 2, 4, 6, 5};
    cout << pythagoreanTriplet(arr);
}