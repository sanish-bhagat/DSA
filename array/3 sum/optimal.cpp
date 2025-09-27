#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N) + O(N log N)
// SC is O(no of unique triplets)

vector<vector<int>> triplet(vector<int> &v)
{
    vector<vector<int>> ans;
    sort(v.begin(), v.end()); // O(N log N)

    int n = v.size();

    for (int i = 0; i < n; i++)
    { // O(N)
        if (i > 0 && v[i] == v[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        { // O(N)
            int sum = v[i] + v[j] + v[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {v[i], v[j], v[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && v[j] == v[j - 1])
                    j++;
                while (j < k && v[k] == v[k + 1])
                    k--;
            }
        }
    }

    return ans;
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

    vector<vector<int>> res = triplet(v);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
