#include <bits/stdc++.h>
using namespace std;

//!TC is O(N)
//! SC is O(1)

double getMedian(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int i = 0, j = 0;

    //m1 to store elements at nth index and m2 to store elements at (n - 1)th index
    int m1 = -1, m2 = -1;

    for (int count = 0; count <= n; count++)
    {

        //har iteration mein m2 ka value pichle iteration wale m1 k value k equal hoga
        m2 = m1;

        //both arrays have remaining elements
        if (i < n && j < n)
        {

            if (a[i] < b[j])
                m1 = a[i++];

            else
                m1 = b[j++];
        }

        //only a[] has remaining
        else if (i < n)
            m1 = a[i++];

        //only b[] has remaining
        else
            m1 = b[j++];
    }

    return (m1 + m2) / 2.0;
}

int main()
{
    vector<int> a = {1, 12, 15, 26, 38};
    vector<int> b = {2, 13, 17, 30, 45};

    cout << getMedian(a, b) << endl;
    return 0;
}