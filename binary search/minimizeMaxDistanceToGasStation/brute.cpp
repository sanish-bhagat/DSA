#include <bits/stdc++.h>
using namespace std;

// TC is O(k * n) + O(n)
// Sc is O(n-1)

long double minimizeMaxDistance(vector<int> v, int k)
{
    int n = v.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = (v[i + 1] - v[i]);
            long double sectionLength = diff / (long double)(howMany[i] + 1);

            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (v[i + 1] - v[i]);
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    int k = 5;

    cout << minimizeMaxDistance(v, k);
}