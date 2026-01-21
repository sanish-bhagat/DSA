#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> calculateSpan(vector<int> &arr)
{
    int n = arr.size();

    // monotonic stack -> stores indices
    stack<int> st;

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        // pop elements while top price <= curr price ->
        // find consecutive days up to curr day for which stock price <= curr price
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        // push the curr day's stock price span -> if stack empty all previous prices are smaller, else
        // find the consecutive no. of days for which curr price is larger
        ans[i] = st.empty() ? i + 1 : i - st.top();

        // push curr index
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> res = calculateSpan(arr);

    for (int x : res)
        cout << x << " ";
}