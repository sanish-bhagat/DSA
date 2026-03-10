#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr)
{
    int n = arr.size();

    // monotonic stack -> stores indices
    // used to find the index of next smaller element on the right
    stack<int> st;
    int count = 0;

    // traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // remove useless elements -> that are >= curr element
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        // find the index of the next smaller element on the right
        int last = st.empty() ? n : st.top();

        // include the no. of subarrays that can be formed in the range(i...last)
        // having the same min element in the starting
        count += (last - i);

        // push the curr index
        st.push(i);
    }

    // return the total no. of subarrays
    return count;
}

int main()
{
    vector<int> arr = {1, 3, 5, 2};
    cout << countSubarrays(arr) << "\n";
    return 0;
}