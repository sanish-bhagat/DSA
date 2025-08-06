#include <bits/stdc++.h>
using namespace std;

// TC is O(min(n,m)) + O(nlogn) + O(mlogm)
// SC is O(1)

void merge(vector<int> &v1, vector<int> &v2, int n, int m)
{
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (v1[left] > v2[right])
        {
            swap(v1[left], v2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

int main()
{
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;

    cout << "Enter the size of the second array: ";
    cin >> m;

    vector<int> v1(n), v2(m);

    cout << "Enter the elements of the 1st array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    cout << "Enter the elements of the 2nd array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    merge(v1, v2, n, m);

    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << v2[i] << " ";
    }
}