#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int visibleBuildings(vector<int> &arr)
{
    // 1st building experiences sunlight
    int cnt = 1;
    int prev = arr[0];

    // traverse through the buildings
    for (int i = 1; i < arr.size(); i++)
    {
        // have found a taller building than the previous one -> sunlight falls on it
        if (arr[i] >= prev)
        {
            cnt++;
            prev = arr[i];
        }
    }

    return cnt;
}

int main()
{
    vector<int> arr = {6, 2, 8, 4, 11, 13};

    cout << visibleBuildings(arr);
}