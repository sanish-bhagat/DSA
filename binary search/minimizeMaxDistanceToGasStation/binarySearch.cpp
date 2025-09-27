#include <bits/stdc++.h>
using namespace std;

// TC is O(n log n) + O(n)
//SC is O(1)

int noOfGasStationReq(vector<int> v, long double dist)
{
    int cnt = 0;

    for (int i = 1; i < v.size(); i++)
    {
        int noInBetween = ((v[i] - v[i - 1]) / dist);

        if (v[i] - v[i - 1] / dist == noInBetween * dist)
        {
            noInBetween--;
        }
        cnt += noInBetween;
    }
    return cnt;
}

long double minimizeMaxDistance(vector<int> v, int k)
{
    int n = v.size();
    long double low = 0, high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(v[i + 1] - v[i]));
    }

    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = noOfGasStationReq(v, mid);

        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    int k = 5;

    cout << minimizeMaxDistance(v, k);
}