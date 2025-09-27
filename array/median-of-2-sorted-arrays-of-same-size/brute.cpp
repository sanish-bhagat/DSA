#include <bits/stdc++.h>
using namespace std;

//! TC is O(n log n)
//! SC is O(n)

double getMedian(vector<int> &a, vector<int> &b)
{

    vector<int> c;

    for (int i = 0; i < a.size(); i++)
        c.push_back(a[i]);

    for (int i = 0; i < b.size(); i++)
        c.push_back(b[i]);

    //?we can use this instead of above for loops
    //?vector<int> c(a.begin(), a.end())
    //?c.insert(c.end(), b.begin(), b.end())

    sort(c.begin(), c.end());

    int n = c.size();

    int mid1 = n / 2;
    int mid2 = (n - 1) / 2;

    return (c[mid1] + c[mid2]) / 2.0;
}

int main()
{
    vector<int> a = {1, 12, 15, 26, 38};
    vector<int> b = {2, 13, 17, 30, 45};

    cout << getMedian(a, b) << endl;
    return 0;
}