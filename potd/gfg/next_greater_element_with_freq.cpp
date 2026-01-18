#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> nextFreqGreater(vector<int> &arr)
{
    int n = arr.size();

    // {element, freq}
    unordered_map<int, int> freq;

    // count freq of every element
    for (int x : arr)
        freq[x]++;

    vector<int> ans(n, -1);

    // stores indices
    stack<int> st;

    // traverse the given arr[] from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // pop elements with freq <= curr element freq
        while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]])
            st.pop();

        // stack not empty then top index element will out ans
        if (!st.empty())
            ans[i] = arr[st.top()];

        // push the curr index
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 1, 3, 2, 1};

    vector<int> res = nextFreqGreater(arr);

    for (int x : res)
        cout << x << " ";
}