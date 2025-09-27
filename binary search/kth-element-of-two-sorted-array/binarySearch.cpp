#include <bits/stdc++.h>
using namespace std;

// TC is O(min(log n1, log n2))

int kthElement(vector<int> v1, vector<int> v2, int k)
{
    int n1 = v1.size(), n2 = v2.size(), n = n1 + n2;

    if (n1 > n2)
        return kthElement(v2, v1, k);

    int low = max((k - n2), 0), high = min(k, n1);
    int left = k;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = v1[mid1];
        if (mid2 < n2)
            r2 = v2[mid2];
        if (mid1 - 1 >= 0)
            l1 = v1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = v2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return INT_MIN;
}

int main()
{
    vector<int> v1 = {2, 4, 6, 8}, v2 = {1, 3, 7, 9, 10};
    int k = 4;

    cout << kthElement(v1, v2, k);
}