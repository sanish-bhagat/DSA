#include <bits/stdc++.h>
using namespace std;

//TC is O(N logN) + [O(log(high)) * O(N)]

bool canWePlace(vector<int> v, int distance, int cows)
{
    int cntCows = 1, last = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i] - last) >= distance)
        {
            cntCows++;
            last = v[i];
        }

        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> v, int cows)
{
    sort(v.begin(), v.end());  //O(N logN)

    int n = v.size();  

     int low = 0,high = v[n-1] - v[0];

     while(low <= high) {
        int mid = (low + high) / 2;

        if(canWePlace(v,mid,cows) == true) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
     }
     return high;
}

int main()
{
    vector<int> v = {0, 3, 4, 7, 9, 10};

    int cows = 4;

    cout << aggressiveCows(v, cows);
}