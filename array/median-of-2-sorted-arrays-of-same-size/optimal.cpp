#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

double getMedian(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int low = 0, high = n;

    while (low <= high)
    {

        int mid1 = (low + high) / 2;

        int mid2 = n - mid1;

        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == n ? INT_MAX : b[mid2]);

        if (l1 <= r2 && l2 <= r1)
        {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }

        if (l1 > r2)
            high = mid1 - 1;

        else
            low = mid1 + 1;
    }

    return 0;
}

int main()
{
    vector<int> a = {1, 12, 15, 26, 38};
    vector<int> b = {2, 13, 17, 30, 45};

    cout << getMedian(a, b) << endl;
    return 0;
}