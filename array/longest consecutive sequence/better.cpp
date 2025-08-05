#include <bits/stdc++.h>
using namespace std;

// TC is O(N*logN) + O(N)
// SC is O(1)

int longestConsecutive(vector<int> &a)
{
    sort(a.begin(), a.end());

    int n = a.size();
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            count += 1;
            lastSmaller = a[i];
        }
        else if (lastSmaller != a[i])
        {
            count = 1;
            lastSmaller = a[i];
        }

        longest = max(longest, count);
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