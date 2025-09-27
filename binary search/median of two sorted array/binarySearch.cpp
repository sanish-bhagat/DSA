#include <bits/stdc++.h>
using namespace std;

// TC is O(min(log n1 , log n2))

double median(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size(), n = n1 + n2;
    
    if (n1 > n2)
        return median(v2, v1);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2; // or mid = (low + high) >> 1
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
            if (n % 2 == 1)
                return max(l1, l2);

            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main()
{
    vector<int> v1 = {1, 3, 4, 7, 10, 12}, v2 = {2, 3, 6, 15};

    cout << median(v1, v2);
}