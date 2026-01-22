#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int subarrayRanges(vector<int> &arr)
{
    int n = arr.size();

    long long maxSum = 0, minSum = 0;

    // monotonic stack -> stores indices
    stack<int> st;

    // min contribution
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
        {
            int mid = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int right = i;

            minSum += (long long)arr[mid] * (mid - left) * (right - mid);
        }

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // max contribution
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] < arr[i]))
        {
            int mid = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int right = i;

            maxSum += (long long)arr[mid] * (mid - left) * (right - mid);
        }

        st.push(i);
    }

    // total sum of all ranges = sum of max of all subarrays - sum of min of all subarrays
    return maxSum - minSum;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    cout << subarrayRanges(arr);
}