#include <bits/stdc++.h>
using namespace std;

// TC is O(n * log n) + O( k * log n)
// Sc is O(n-1)

long double minimizeMaxDistance(vector<int> v, int k)
{
    int n = v.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({v[i + 1] - v[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;

        long double iniDiff = v[secInd + 1] - v[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    int k = 5;

    cout << minimizeMaxDistance(v, k);
}