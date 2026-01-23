#include <bits/stdc++.h>
using namespace std;

int maxPeople(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);

    // monotonic decreasing stack, {height, count}
    stack<pair<int, int>> st;

    // step1: visible in left
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        // pop all smaller elements in left -> they are visible
        while (!st.empty() && st.top().first < arr[i])
        {
            cnt += st.top().second;
            st.pop();
        }

        // no. of people visible in the left for the curr element
        left[i] = cnt;

        // push the curr element height and the count
        st.push({arr[i], cnt + 1});
    }

    // pop all the left out elements
    while (!st.empty())
        st.pop();

    // step2: visible in right
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;

        // pop all smaller elements in right -> they are visible
        while (!st.empty() && st.top().first < arr[i])
        {
            cnt += st.top().second;
            st.pop();
        }

        // no. of people visible in the left for the curr element
        right[i] = cnt;

        // push the curr element height and the count
        st.push({arr[i], cnt + 1});
    }

    int ans = INT_MIN;

    // step3: pick the no. of max person visible including them
    for (int i = 0; i < n; i++)
        ans = max(ans, left[i] + right[i] + 1);

    return ans;
}

int main()
{
    vector<int> arr = {5, 3, 4, 2, 1, 6};
    cout << maxPeople(arr);
}