#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int catchThieves(vector<char> &arr, int k)
{
    int n = arr.size(), count = 0;

    // store the indices of police and thief
    vector<int> police, thief;

    // fill police[] and thief[]
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
            police.push_back(i);

        else if (arr[i] == 'T')
            thief.push_back(i);
    }

    int i = 0, j = 0;

    // traverse through the stored[] indices
    while (i < police.size() && j < thief.size())
    {
        // theif is in police caughting range -> increment the count
        if (abs(police[i] - thief[j]) <= k)
            count++, i++, k++;

        // else, move ptr of smaller index -> to reduce distance
        else if (police[i] < thief[j])
            i++;

        else
            j++;
    }

    // return the count of the total thieves that have been caught
    return count;
}

int main()
{
    int k = 1;
    vector<char> arr = {'P', 'T', 'T', 'P', 'T'};

    cout << catchThieves(arr, k);
}