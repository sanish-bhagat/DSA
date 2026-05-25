#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool checkElements(int start, int end, vector<int> &arr)
{
    // keep track of the elements present in the arr[]
    unordered_set<int> st(arr.begin(), arr.end());

    // traverse through the given range
    for (int i = start; i <= end; i++)
    {
        // if any element in the range is missing -> return false
        if (!st.count(i))
            return false;
    }

    // all elements in the range are present, return true
    return true;
}

int main()
{
    int start = 2, end = 5;
    vector<int> arr = {1, 4, 5, 2, 7, 8, 3};
    cout << checkElements(start, end, arr);
}