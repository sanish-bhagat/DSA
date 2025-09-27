#include <bits/stdc++.h>
using namespace std;

// TC is O(n+m) + O(n+m)
// SC is O(n+m)

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &v1, vector<int> &v2, int n, int m)
{
    vector<int> v3(n + m);
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m)
    {
        if (v1[left] <= v2[right])
        {
            v3[index] = v1[left];
            left++, index++;
        }
        else
        {
            v3[index] = v2[right];
            right++, index++;
        }
    }
    while (left < n)
    {
        v3[index] = v1[left];
        left++, index++;
    }

    while (right < m)
    {
        v3[index] = v2[right];
        right++, index++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            v1[i] = v3[i];
        else
            v2[i - n] = v3[i];
    }
    display(v1);
    display(v2);
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
    cout << endl;

    merge(v1, v2, n, m);
}