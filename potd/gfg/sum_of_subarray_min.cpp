#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int sumSubMins(vector<int> &arr)
{
    int n = arr.size();

    // store the distance of every element from the left and right
    vector<int> left(n), right(n);

    // monotonic stack
    stack<int> st;

    // traverse from left to right
    for (int i = 0; i < n; i++)
    {
        // useless elements -> remove the larger elements
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        // curr element distance to previous smaller element
        left[i] = st.empty() ? i + 1 : i - st.top();

        // push the curr index
        st.push(i);
    }

    // reset the stack
    while (!st.empty())
        st.pop();

    // traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // useless elements -> remove the larger elements
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        // curr element distance to next smaller element
        right[n] = st.empty() ? n - i : st.top() - i;

        // push the curr index
        st.push(i);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // contribution of curr element
        res += arr[i] * left[i] * right[i];
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << sumSubMins(arr) << endl;
    return 0;
}