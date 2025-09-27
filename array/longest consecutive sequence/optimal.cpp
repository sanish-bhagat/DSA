#include <bits/stdc++.h>
using namespace std;

// TC is O(3N) , assuming that the TC for set is O(1) {for worst case TC is O(N)  *rarely happens}
// SC is O(N)

int longestConsecutive(vector<int> &a)
{
    int n = a.size();
    int longest = 1;

    unordered_set<int> st;

    // O(N)

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    // O(N) + O(N) = O(2N)
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;

            // O(N)

            while (st.find(x + 1) != st.end())
            {
                x += 1;
                count += 1;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    int n, element;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    cout << longestConsecutive(arr);
}