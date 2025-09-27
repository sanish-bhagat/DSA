#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)
// SC is O(1)

pair<int, int> repeatingAndMissing(vector<int> &v, int n)
{
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                count++;
            }
        }
        if (count == 2)
            repeating = i;
        else if (count == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }

    return make_pair(repeating, missing);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pair<int, int> res = repeatingAndMissing(v, n);

    cout << res.first << " " << res.second;
}