#include <bits/stdc++.h>
using namespace std;

// Finds the interval containing the given rank
int findInterval(vector<int> &prefix, int low, int high, int rank)
{
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (prefix[mid] < rank)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

//! TC is O(n + qlogn)
//! SC is O(n)

vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank)
{
    int n = l.size();

    // Stores the cumulative number of marks till each interval
    vector<int> prefix(n);

    prefix[0] = r[0] - l[0] + 1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + (r[i] - l[i] + 1);
    }

    vector<int> ans(rank.size());

    // Process every query
    for (int i = 0; i < rank.size(); i++)
    {
        // Find the interval containing the required rank
        int idx = findInterval(prefix, 0, n - 1, rank[i]);

        // Compute the corresponding mark
        int diff = prefix[idx] - rank[i];
        ans[i] = r[idx] - diff;
    }

    return ans;
}

int main()
{
    vector<int> l = {1, 6, 14};
    vector<int> r = {3, 9, 15};
    vector<int> rank = {2, 5, 8};

    vector<int> ans = getMarks(l, r, rank);

    for (int mark : ans)
        cout << mark << " ";

    cout << endl;

    return 0;
}