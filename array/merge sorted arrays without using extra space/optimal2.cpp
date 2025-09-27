#include <bits/stdc++.h>
using namespace std;

// TC is O(log(n+m)) * O(n+m) , log having base 2
// SC is O(1)

void swapIfGreater(vector<int> &v1, vector<int> v2, int idx1, int idx2)
{
    if (v1[idx1] > v2[idx2])
    {
        swap(v1[idx1], v2[idx2]);
    }
}

void merge(vector<int> &v1, vector<int> &v2, int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // v1 and v2
            if (left < n && right >= n)
            {
                swapIfGreater(v1, v2, left, right - n);
            }
            // v2 and v2
            else if (left >= n)
            {
                swapIfGreater(v2, v2, left - n, right - n);
            }
            // v1 and v1
            else
            {
                swapIfGreater(v1, v1, left, right);
            }
            left++, right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    int n, m;
    cout << "Enter the size of the 1st array: ";
    cin >> n;

    cout << "Enter the size of the 2nd array: ";
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

    cout << endl;

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