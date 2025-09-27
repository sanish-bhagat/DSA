#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)
// SC is O(1)

bool linearSearch(vector<int> &a, int num)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}

int longestConsecutive(vector<int> &a)
{
    int longest = 1;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 1;

        while (linearSearch(a, x + 1) == true)
        {
            x = x + 1;
            count += 1;
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