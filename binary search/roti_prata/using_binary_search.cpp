#include <bits/stdc++.h>
using namespace std;

//! O(log(maxTime) * l * maxPratas)
//! SC is O(l)   : as we are storing the value of cook's rank

bool isPossible(vector<int> &cook, int l, int p, int maxTime)
{
    int parataCount = 0;

    for (int i = 0; i < l; i++)
    {
        int time = 0;  //time taken by each cook
        int r = cook[i];    
        int count = 0;  //count of pratas made by each cook

        while (time + (r * (count + 1)) <= maxTime)
        {
            count++;
            time += r * count;  //time for the next prata
        }

        parataCount += count;

        if (parataCount >= p)
            return true;
    }

    return false;
}

int minTime(vector<int> &cook, int l, int p)
{
    int low = 0, high = 1e7;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (isPossible(cook, l, p, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    vector<int> cook = {1, 2, 3, 4};
    int l = 4;
    int p = 10;
    cout << minTime(cook, l, p);
}